#pragma once

#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "list.h"

/**
 * String function header.
*/
char *os_strcat(char *head, bool freeHead, char *tail, bool freeTail);