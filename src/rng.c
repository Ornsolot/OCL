#include "ocl.h"

/**
 * \warning OBSCURE ARCANE OF BLACK WIZARDRY COMPUTER MAGIC to mix three number in one.
 * \brief mix 3 unsignd long integer with boolean wizardry to create a seed.
 * \warning when i was coding this only god an i know what i was doing. Now only gode know.
 * \param a a random size_t like clock().
 * \param b a random size_t like time().
 * \param c a random size_t like getpid().
 * \return size_t, the new seed.
 */
static size_t mix(size_t a, size_t b, size_t c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    
    return (c);
}

/**
 * \brief set the seed of the random number generator.
 */
void setRNG()
{
    srand(mix(clock(), time(NULL), getpid()));
}

/**
 * \brief Give a random unsigned integer.
 * \param min the minimum value the number can take.
 * \param max the maximum value the number can take.
 * \return size_t, random unsigned integer.
 */
size_t getNaturalRNG(size_t min, size_t max)
{
    return (rand() % (max - min) + min);
}

double getFloatRNG(double min, double max)
{
    return ((rand() / RAND_MAX) * (max - min) + min);
}

/**
 * \brief   Arrange the N elements of ARRAY in random order.
 * \warning Only effective if N is much smaller than RAND_MAX (32767) !
 * \param   array the array to shuffle.
 * \param   length the array size.
 */
void shuffle(void **array, size_t length)
{
    void  *swap = NULL;
    size_t rng = 0;

    for (size_t i = 0; i < length; i++) {
        rng = i + rand() / (RAND_MAX / (length - i) + 1);
        swap = array[rng];
        array[rng] = array[i];
        array[i] = swap;
    }
}