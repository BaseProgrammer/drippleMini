/*
    drippleMini OS (C) 2021
    LICENSE @ ROOT DIRECTORY
    github_url: https://github.com/BaseProgrammer/drippleMini

*/

#include "ports.h"

u8 port_byte_in(u16 port)
{
    u8 result;

    __asm__("in %%dx, %%al"
            : "=a"(result)
            : "d"(port));
    return result;
}

void port_byte_out(u16 port, u8 data)
{
    __asm__("out %%al, %%dx"
            :
            : "a"(data), "d"(port));
}

u16 port_word_in(u16 port)
{
    u16 result;
    
    __asm__("in %%dx, %%ax"
            : "=a"(result)
            : "d"(port));
    return result;
}

void port_word_out(u16 port, u16 data)
{
    __asm__("out %%ax, %%dx"
            :
            : "a"(data), "d"(port));
}