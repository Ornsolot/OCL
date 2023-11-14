#include "ocl.h"

static link_t *setLink(char *name, void *data, link_t *prev, link_t *next)
{
    link_t *link = malloc(sizeof(link_t));

    if (link) {
        link->name = setStr(name);
        link->data = data;
        link->prev = prev;
        link->next = next;
    }
    return (link);
}

list_t *setList()
{
    list_t *list = malloc(sizeof(list_t));

    if (list) {
        list->head = NULL;
        list->tail = NULL;
        if (!(list->sent = setLink("Sentinel", NULL, NULL, NULL)))
            free(list);
    }
    return (list);
}

bool setHead(list_t *list, char *name, void *data)
{
    link_t *node = setLink(name, data, list->sent->next, list->sent);

    if (node) {
        list->sent->next->next = node;
        list->sent->next = node;
    }
    return (node != NULL);
}

bool setTail(list_t *list, char *name, void *data)
{
    link_t *node = setLink(name, data, list->sent, list->sent->prev);

    if (node) {
        list->sent->prev->prev = node;
        list->sent->prev = node;
    }
    return (node != NULL);
}

void *getNode(list_t *list, char *name)
{
    link_t *node = (list) ? list->sent->prev : NULL;
    
    if (node && name)
        while (strcmp(name, node->name->data) != 0 && node->data != NULL)
            node = node->next;
    return (node);
}

void *unsetList(list_t *list)
{
    link_t *node = (list) ? list->sent->next : NULL;
    
    while (node && node->data) {
        node = node->next;
        free(node->prev);
    }
    return (node->data);
}