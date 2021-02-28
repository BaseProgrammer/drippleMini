/*
    drippleMini OS (C) 2021
    LICENSE @ ROOT DIRECTORY
    github_url: https://github.com/BaseProgrammer/drippleMini

*/

#ifndef IDT_H
#define IDT_H

#include <stdint.h>

// A segment selector
#define KERNEL_CS 0x08

// Defining interupt gate handler
typedef struct
{

    uint16_t low_offset; // 16 bit handler function address
    uint16_t sel;        // Kernel segment selector
    uint8_t always0;
    uint8_t flags;
    uint16_t high_offset;

} __attribute__((packed)) idt_gate_t;

// "lidt" from assembly instruction reads this
typedef struct
{

    uint16_t limit;
    uint32_t base;

} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256
idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

void set_idt_gate(int n, uint32_t handler);
void set_idt();

#endif