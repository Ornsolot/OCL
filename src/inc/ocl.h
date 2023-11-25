#pragma once

#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#include "type.h"

void setRNG();
size_t getNaturalRNG(size_t min, size_t max);
double getFloatRNG(double min, double max);
void shuffle(void **array, size_t length);