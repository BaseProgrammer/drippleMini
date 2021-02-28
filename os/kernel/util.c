/*
    drippleMini OS (C) 2021
    LICENSE @ ROOT DIRECTORY
    github_url: https://github.com/BaseProgrammer/drippleMini

*/

#include "util.h"

void memory_copy(char *source, char *dest, int nbytes)
{
    int i;
    for (i = 0; i < nbytes; i++)
    {
        *(dest + i) = *(source + i);
    }
}

void memory_set(u8 *dest, u8 value, u32 length)
{
    u8 *temp = (u8 *)dest;
    for (; length != 0; length--)
        *temp++ = value;
}

void asciiIntConverter(int n, char str[])
{
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do
    {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        str[i++] = '-';
    str[i] = '\0';
}

void reverse(char s[])
{
    int a, b, c;
    for (b = 0, c = strlen(s) - 1; b < c; b++, c--)
    {
        a = s[b];
        s[b] = s[c];
        s[c] = a;
    }
}

int strlen(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}