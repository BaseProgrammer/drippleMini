/*
    drippleMini OS (C) 2021
    LICENSE @ ROOT DIRECTORY
    github_url: https://github.com/BaseProgrammer/drippleMini

*/

#include "string.h"

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

    reverse(str);
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

void append(char s[], char n)
{
    int len = strlen(s);
    s[len] = n;
    s[len + 1] = '\0';
}

void backspace(char s[])
{
    int len = strlen(s);
    s[len - 1] = '\0';
}

int strcmp(char s1[], char s2[])
{
    int i;
    for (i = 0; s1[i] == s2[i]; i++)
    {
        if (s1[i] == '\0')
            return 0;
    }
    return s1[i] - s2[i];
}
