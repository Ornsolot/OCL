#include "ocl.h"

static int RTC_getTicks()
{
    static int SysCallCode[] = {0xD201422B,0x60F20000,0x80010070};
    static int (*SysCall)(int R4, int R5, int R6, int R7, int FNo ) = (void*)&SysCallCode;
    
    return (*SysCall)(0, 0, 0, 0, 0x3B);
}

void setRNG() {
    srand(RTC_getTicks());
}

size_t getRNG(size_t min, size_t max)
{
    return (rand() % (max - min) + min);
}

double rand_float_ab(double min, double max)
{
    return ((rand() / RAND_MAX) * (max - min) + min);
}