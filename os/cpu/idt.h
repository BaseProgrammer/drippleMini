/*
    drippleMini OS (C) 2021
    LICENSE @ ROOT DIRECTORY
    github_url: https://github.com/BaseProgrammer/drippleMini

*/

#ifndef IDT_H
#define IDT_H

#include "type.h"

// A segment selector
#define KERNEL_CS 0x08

// Defining interupt gate handler
typedef struct
{

    u16 low_offset; // 16 bit handler function address
    u16 sel;        // Kernel segment selector
    u8 always0;
    u8 flags;
    u16 high_offset;

} __attribute__((packed)) idt_gate_t;

// "lidt" from assembly instruction reads this
typedef struct
{

    u16 limit;
    u32 base;

} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256
idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

void set_idt_gate(int n, u32 handler);
void set_idt();

#endif