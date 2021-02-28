/*
    drippleMini OS (C) 2021
    LICENSE @ ROOT DIRECTORY
    github_url: https://github.com/BaseProgrammer/drippleMini

*/

#include "../cpu/isr.h"
#include "../cpu/timer.h"
#include "../drivers/keyboard.h"

void main() {
    isr_install();

    asm volatile("sti");
    init_timer(50);
    init_keyboard();
}