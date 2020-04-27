# operatingsystemtoolkit
operating system tool kit

opearting tool kit version 0.1, 

coded on linux, might not work on windows devices. but i'm sure you can figure that out.
needs nasm gcc and qemu.


how to create?

make a file called kernel.c

within kernel.c make a new entrypoint called 
void kmain(){



}

within that entry point. you may use the the commands. 
IF you do not want to store it at kmain. go to bootsector.asm , and then go find "extern kmain" change it to your new function name.
the onwards go to the loader label and change the call kmain to your new function name. 

if you do not want to use the file "kernel.c" goto build and then press CTRL - F  and find kernel.c and change it.




created in c, x64 nasm asm.

