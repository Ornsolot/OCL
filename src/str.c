#include "osl.h"
#include <stdio.h>

size_t os_strlen(char *str)
{
    size_t len = 0;
    
    if (str)
        while (str[len] != '\0')
            len++;
    return (len);
}

char *os_strcat(char *head, bool freeHead, char *tail, bool freeTail)
{
    char *str = malloc(sizeof(char) * (os_strlen(head) + os_strlen(tail)));
    size_t len = 0;

    if (str) {
        for (len = 0; head[len] != '\0'; len++)
            str[len] = head[len];
        for (size_t i = 0; tail[i] != '\0'; i++)
            str[len+i] = tail[i];
    }
    if (freeHead)
        free(head);
    if (freeTail)
        free(tail);
    return (str);
}

bool os_strcut(char *str, char **head, char **tail, size_t index)
{
    if (*tail != NULL)
        free(*tail);
    if (*head != NULL)
        free(*head);
    *tail = malloc(sizeof(char) * (os_strlen(str) - index - 1));
    *head = malloc(sizeof(char) * index);
    if (*head && *tail) {
        for (size_t i = 0; str[i + index] != '\0'; i++)
            (*tail)[i] = str[i + index + 1];
        for (size_t i = 0; i < index; i++)
            (*head)[i] = str[i];
    }
    return (head && tail);
}