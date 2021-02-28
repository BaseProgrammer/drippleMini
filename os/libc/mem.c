#include "mem.h"

void memory_copy(uint8_t *source, uint8_t *dest, int nbytes)
{
    int i;
    for (i = 0; i < nbytes; i++)
    {
        *(dest + i) = *(source + i);
    }
}

void memory_set(uint8_t *dest, uint8_t val, uint32_t len)
{
    uint8_t *temp = (uint8_t *)dest;
    for (; len != 0; len--)
        *temp++ = val;
}

uint32_t free_memory_address = 0x10000;

uint32_t kmalloc(uint32_t size, int align, uint32_t *physical_address)
{
    if (align == 1 && (free_memory_address & 0xFFFFF000))
    {
        free_memory_address &= 0xFFFFF000;
        free_memory_address += 0x1000;
    }

    if (physical_address)
        *physical_address = free_memory_address;

    uint32_t ret = free_memory_address;
    free_memory_address += size; 
    return ret;
}