/*
    drippleMini OS (C) 2021
    LICENSE @ ROOT DIRECTORY
    github_url: https://github.com/BaseProgrammer/drippleMini

*/

#ifndef PORTS_H
#define PORTS_H

#include <stdint.h>

unsigned char port_byte_in(uint16_t port);
void port_byte_out(uint16_t port, uint8_t data);
unsigned short port_word_in(uint16_t port);
void port_word_out(uint16_t port, uint16_t data);

#endif