#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <linux/uinput.h>

int main() {
    struct input_event e;
    int i = open("/dev/input/event3", O_RDONLY);
    int u = open("/dev/uinput", O_WRONLY);

    ioctl(u, UI_SET_EVBIT, EV_KEY);
    for(int k=0; k<256; ioctl(u, UI_SET_KEYBIT, k++));
    struct uinput_setup s = {.name = "clone"};
    ioctl(u, UI_DEV_SETUP, &s);
    ioctl(u, UI_DEV_CREATE);

    while(read(i, &e, sizeof(e)) == sizeof(e)) {
        if(e.type == EV_KEY) {
            write(u, &e, sizeof(e));
            struct input_event syn = {.type = EV_SYN};
            write(u, &syn, sizeof(syn));
        }
    }
}
