#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <linux/uinput.h>

// Setup UInput Device
int setup_uinput() {
    int uinput_fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
    if (uinput_fd < 0) {
        perror("Unable to open /dev/uinput");
        exit(EXIT_FAILURE);
    }

    // Enable key events and all possible keys
    ioctl(uinput_fd, UI_SET_EVBIT, EV_KEY);
    for (int key = 0; key <= KEY_MAX; key++) {
        ioctl(uinput_fd, UI_SET_KEYBIT, key);
    }

    // Configure virtual device
    struct uinput_setup usetup = {
        .name = "Virtual Keyboard",
        .id = {
            .bustype = BUS_USB,
            .vendor  = 0x1234,
            .product = 0x5678,
            .version = 1
        }
    };

    ioctl(uinput_fd, UI_DEV_SETUP, &usetup);
    ioctl(uinput_fd, UI_DEV_CREATE);

    return uinput_fd;
}

int main() {
    struct input_event ev;
    const char *dev_path = "/dev/input/event3";
    int input_fd = open(dev_path, O_RDONLY);
    int uinput_fd = setup_uinput();

    if (input_fd == -1) {
        perror("Unable to open input device");
        exit(EXIT_FAILURE);
    }

    printf("Listening for keystrokes (and replicating)...\n");

    // Read events and replicate them
    while (read(input_fd, &ev, sizeof(ev)) == sizeof(ev)) {
        if (ev.type == EV_KEY) {
            // Log the event (keycode and action)
            printf("Key %d %s\n", ev.code, ev.value ? "Pressed" : "Released");
            
            // Replicate the event via uinput
            write(uinput_fd, &ev, sizeof(ev));
            struct input_event syn = {.type = EV_SYN, .code = SYN_REPORT, .value = 0};
            write(uinput_fd, &syn, sizeof(syn));
        }
    }

    ioctl(uinput_fd, UI_DEV_DESTROY);
    close(uinput_fd);
    close(input_fd);
    return 0;
}
