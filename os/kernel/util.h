/*
    drippleMini OS (C) 2021
    LICENSE @ ROOT DIRECTORY
    github_url: https://github.com/BaseProgrammer/drippleMini

*/

#ifndef UTIL_H
#define UTIL_H

#include "../cpu/types.h"

void memory_copy(char *source, char *dest, int nbytes);
void memory_set(u8 *dest, u8 value, u32 length);
void asciiIntConverter(int n, char str[]);

void reverse(char s[]);
int strlen(char s[]);

#endif