/*
    drippleMini OS (C) 2021
    LICENSE @ ROOT DIRECTORY
    github_url: https://github.com/BaseProgrammer/drippleMini

*/

#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"

void main()
{
    isr_install();
    irq_install();

    kprint("Type something, it will go through the kernel\n"
           "Type END to halt the CPU\n> ");
}

void user_input(char *input)
{
    if (strcmp(input, "END") == 0)
    {
        kprint("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    }

    if (strcmp(input, "CLEAR") == 0)
    {
        clear_screen();
    }

    kprint("You have entered: ");
    kprint(input);
    kprint("\n> ");
}