#include "ocl.h"

/**
 * \brief   Get the length of a Charcater String.
 * \param   string Character String to compute.
 * \return  size_t, unsigned integer representing the length of the character string.
 */
static size_t strLen(char *string)
{
    size_t len = 0;
    
    if (string)
        while (string[len] != '\0')
            len++;
    return (len);
}

/**
 * \brief   Get the a copy of a Charcater String.
 * \param   string Character String to compute.
 * \param   from unsigned integer where to start the copy.
 * \param   to unsigned integer where to end the copy.
 * \return  char *, The copy of the Character String.
 */
static char *strCopy(char *string, size_t from, size_t to)
{
    char *copy = MALLOCSTR(strLen(string) - (from + to));

    if (copy)
        for (size_t i = from; i < to; i++)
            copy[i] = string[i];
    return (copy);
}

/**
 * \brief   Concatenate two Character Strings.
 * \param   head Head of the future Character String to compute.
 * \param   tail Tail of the future Character String to compute.
 * \return  char *, Concatenation of the two Charcater Strings.
 */
char *strCat(char *head, char *tail)
{
    char *str = MALLOCSTR(strLen(head) + strLen(tail));
    size_t len = 0;

    if (str) {
        if (head)
            for (len = 0; head[len] != '\0'; len++)
                str[len] = head[len];
        if (tail)
            for (size_t i = 0; tail[i] != '\0'; i++)
                str[len+i] = tail[i];
    }
    return (str);
}

/**
 * \brief   create a String_t Object.
 * \param   data Character string serving has String_t Object data.
 * \return  Object String_t Object.
 */
String_t *setStr(char *data)
{
    size_t len = strLen(data);
    String_t *str = len > 0 ? malloc(sizeof(String_t)) NULL;

    if (str) {
        str->data = MALLOCSTR(len);
        for (size_t i = 0; i < len ; i++)
            str->data[i] = data[i];
        str->length = len;
    }
    return (str);
}

/**
 * \brief Remove String_t object and free it's memory.
 * \param string String_t Object to free.
 */
void unsetStr(String_t *string)
{
    if (string) {
        if (string->data)
            free(string->data);
        free(string);
    }
}

/**
 * \brief   Change the String_t Object data (Character String).
 * \param   string Object to change.
 * \param   data Character string serving has String_t Object new data.
 * \param   bool buffer if the Character String is a buffer, if true it free new data.
 * \return  Boolean.
 */
bool resetStr(String_t *string, char *data, bool buffer)
{
    unsetStr(string);
    string = setStr(data);
    if (buffer)
        free(data);
    return (string != NULL);
}

/**
 * \brief   Concatenate multiple String_t Object data (Character String) and free them.
 * \param   count the number of string Object to concatenate.
 * \return  Boolean.
 */
String_t *catStr(size_t count, ...)
{
    String_t *string = NULL;
    String_t *buffer = NULL;
    va_list arg;

    va_start(arg, count);
    for (size_t i = 0; i < count; i++) {
        if ((buffer = va_arg(arg, String_t *)) != NULL) {
            resetStr(string, strCat(string->data, buffer->data), true);
            unsetStr(buffer);
        }
    }
    va_end(arg);
    return (string);
}

/**
 * \brief   Cut two Character Strings.
 * \param   string The string to cut in half.
 * \param   head New String_t Object representing the base of the previous string.
 * \param   tail New String_t Object representing the end of the previous string.
 * \return  Boolean.
 */
bool cutStr(String_t *string, String_t *head, String_t *tail, size_t index)
{
    if (string && string->data) {
        resetStr(head, strCopy(string->data, 0, index), true);
        resetStr(tail, strCopy(string->data, index + 1, string->length), true);
    }
    return (head && tail);
}