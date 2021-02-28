/*
    drippleMini OS (C) 2021
    LICENSE @ ROOT DIRECTORY
    github_url: https://github.com/BaseProgrammer/drippleMini

*/

#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"
#include "../libc/mem.h"
#include <stdint.h>

void kernel_main()
{
    isr_install();
    irq_install();

    asm("int $2");
    asm("int $3");

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
    else if (strcmp(input, "CLEAR") == 0)
        clear_screen();

    else if (strcmp(input, "HELP") == 0)
        kprint("CLEAR\nEND\nHELP\nPAGE\nSAY 'MESSAGE'");

    else if (strcmp(input, "SAY") == 0)
        kprint(input + 4);

    else if (strcmp(input, "PAGE") == 0)
    {
        uint32_t physical_address;
        uint32_t page = kmalloc(1000, 1, &physical_address);
        char page_string[16] = "";
        asciiHexConverter(page, page_string);
        char physical_string[16] = "";
        asciiHexConverter(physical_address, physical_string);
        kprint("Page: ");
        kprint(page_string);
        kprint(", physical address: ");
        kprint(physical_string);
        kprint("\n");
    }
    else
        kprint("shell: unknown command");

    kprint("\n> ");
}