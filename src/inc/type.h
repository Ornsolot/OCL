#include "ocl.h"

#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#define MALLOCSTR(len) (malloc(sizeof(char) * len))

/**
 * \struct  String_t
 * \brief   String_t is a small object for managing character strings.
 */
typedef struct osString_s {
    char  *data;
    size_t len;
} String_t;

/**
 * String function header.
 */
String_t *setStr(char *data);
void unsetStr(String_t *string);
String_t *catStr(size_t count, ...);
char *strCat(char *head, char *tail);

// TO TEST
typedef struct Os2DLink_s {
    String_t            *name;
    void                *data;
    struct Os2DLink_s   *prev;
    struct Os2DLink_s   *next;
} link_t;

typedef struct Os2DList {
    link_t *head;
    link_t *tail;
    link_t *sent;
} list_t;


