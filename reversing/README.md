# reversing

- [x] Beatles - medium (debugger - gdb)
- [x] Elvis - hard (disassembler - decomplier - ghidra)
- [x] Madonna - easy (plain text)

# solving Madonna

in the terminal run:

```bash

strings Madonna

```

we will get this output

![strings output](assets/stirngs-madonna-output.png)

and we can see that there is one string that feels out of place

so when we try to run it

```bash

./Madonna RayOfLight

```

we get this

![solution](assets/madonna-RayOfLight-output.png)

the password is `RayOfLight`

solved!

# solving Beatles

when you try to run `strings` in the terminal on the Beatles elf binary you will see nothing suspicios

so next thing to try is using a debugger (`gdb`)

```bash

gdb Beatles

```

![gdb start](assets/beatles-gdb-start.png)

inside of the `gdb` console

run the program once without any arguments, so that we can put a breakpoint onto it later

```bash

run

```

![run](assets/gdb-run-no-arg.png)

disassemble the main function

```bash

disassemble main

```

![dis main](assets/disassemble-main.png)

we need to take the address of the `strcmp` function so that we can put a breakpoint there

in this case

```bash

b *0x0000555555555287

```

![breakpoint](assets/breakpoint.png)

now we will run it with an arbitrary argument (the letter a repeating 11 times)

```bash

run aaaaaaaaaaa

```

![run arguments](assets/run-arg.png)

![verifying](assets/checking-params.png)

now that the program has stopped at the breakpoint we set before, we are able to see the contents of the registers

and as we can see one of them is the argument we provided so that means the second one must be the password

let's check

![solution](assets/beatles-Misery-output.png)

the password is `Misery`

solved!

# solving Elvis

running `strings` will not show anything

trying to connect will debugger will not work

![gdb fail](assets/elvis-gdb.png)

next thing to try is deocmpiling

- open ghidra
- create new project (CTRL + N) or (File > New Project...)
- name the project
- import the Beatles elf binary (I) or (File > Import File...)
- double-click on it to open it using the tool `CodeBrowser`
in the window that has opened, on the left side, from the 3 vertical boxes, in the one labeled `Symbol tree`
- double-click on Functions > main
this will open the decopiled view of the main function in the window on the right

now we will select all the decomplied code and will paste it into a `.c` file for further examination

[decompiled](Elvis-decompiled.c)

after deobfuscating you get this

[deobfuscated](Elvis-deobfuscated.c)

after adding the relevant line and nuking the line that exits the program we can compile and run it with an arbitrary argument

compile with the below command

```bash

gcc Elvis-deobfuscated.c -o elvis-deobf

```

then run it with the below command

```bash

./elvis-deobf aaaaaaaaaaa

```

![running elf](assets/running-elvis-deobf.png)

the password seems to be `HoundDog`, let's check

```bash

./Elvis HoundDog

```

![solution](assets/elvis-hound-dog.png)

the password is `HoundDog`

solved!

> [!NOTE]
> from further experiments it seems that when provided with any substring of the password `HoundDog` the Elvis elf will print `Well done`

![substring](assets/Elvis-H-output.png)
