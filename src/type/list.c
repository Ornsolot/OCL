#include "ocl.h"

/**
 * \brief   Create a node of a linked liste.
 * \param   name Character String reprsenting the id of the node.
 * \param   data The data to store in the node.
 * \param   prev The node before.
 * \param   prev The node after.
 * \return  The newly created node or NULL.
 */
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

/**
 * \brief   Create an empty linked liste.
 * \return  The newly created linked list or NULL.
 */
list_t *setList()
{
    list_t *list = malloc(sizeof(list_t));

    if (list) {
        list->length = 0;
        list->head = NULL;
        list->tail = NULL;
        if (!(list->sentinel = setLink("Sentinel", NULL, NULL, NULL)))
            free(list);
    }
    return (list);
}

/**
 * \brief   Set a node at the start of a linked liste.
 * \param   name Character String reprsenting the id of the node.
 * \param   data The data to store in the node.
 * \return  Boolean.
 */
bool setHead(list_t *list, char *name, void *data)
{
    link_t *node = setLink(name, data, list->sentinel->next, list->sentinel);

    if (node) {
        list->sentinel->next->next = node;
        list->sentinel->next = node;
    }
    return (node != NULL);
}

/**
 * \brief   Set a node at the end of a linked liste.
 * \param   name Character String reprsenting the id of the node.
 * \param   data The data to store in the node.
 * \return  Boolean.
 */
bool setTail(list_t *list, char *name, void *data)
{
    link_t *node = setLink(name, data, list->sentinel, list->sentinel->prev);

    if (node) {
        list->sentinel->prev->prev = node;
        list->sentinel->prev = node;
    }
    return (node != NULL);
}

/**
 * \brief   Get a node from is name.
 * \param   name Character String reprsenting the id of the node.
 * \return  the node corresponding or NULL.
 */
link_t *getNodeFromeName(list_t *list, char *name)
{
    link_t *node = (list) ? list->sentinel->prev  NULL;
    
    if (node && name)
        while (strcmp(name, node->name->data) != 0 && node->data != NULL)
            node = node->next;
    return (node);
}

/**
 * \brief   Remove a node from the linked liste (You have to free them yourself).
 * \param   name Character String reprsenting the id of the node.
 * \return  Boolean.
 */
link_t *rmNode(list_t *list, char *name)
{
    link_t *node = (list) ? list->sentinel->prev  NULL;
    
    if (node && name) {
        while (strcmp(name, node->name->data) != 0 && node->data != NULL)
            node = node->next;
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->prev = NULL;
        node->next = NULL;
    }
    return (node);
}

/**
 * [W.I.P]
 */
void *unsetList(list_t *list)
{
    link_t *node = (list) ? list->sentinel->next  NULL;
    
    if (node) {
        while (node->data) {
            node = node->next;
            free(node->prev);
        }
        free(list);
    }
    return (node->data);
}