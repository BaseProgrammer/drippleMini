#include "mem.h"

void memory_copy(u8 *source, u8 *dest, int nbytes)
{
    int i;
    for (i = 0; i < nbytes; i++)
    {
        *(dest + i) = *(source + i);
    }
}

void memory_set(u8 *dest, u8 val, u32 len)
{
    u8 *temp = (u8 *)dest;
    for (; len != 0; len--)
        *temp++ = val;
}

u32 free_memory_address = 0x10000;

u32 kmalloc(u32 size, int align, u32 *physical_address)
{
    if (align == 1 && (free_memory_address & 0xFFFFF000))
    {
        free_memory_address &= 0xFFFFF000;
        free_memory_address += 0x1000;
    }

    if (physical_address)
        *physical_address = free_memory_address;

    u32 ret = free_memory_address;
    free_memory_address += size; 
    return ret;
}