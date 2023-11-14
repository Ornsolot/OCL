#pragma once

#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "type.h"

/**
 * String function header.
 */
String_t *setStr(char *data);
String_t *catStr(size_t count, ...);
char *strCat(char *head, char *tail);