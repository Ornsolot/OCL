#include "ocl.h"

static size_t getfileSize(char *path)
{
    struct stat buffer;

    return ((stat(path, &buffer) != 0) ? -1 : buffer.st_size);
}


char *readFile(char *path)
{
    size_t size = getfileSize(path);
    char *buffer = (size > 0) ? malloc(size * sizeof(char)) : NULL;
    int fd = open(path, O_RDONLY);
    
    if (fd != -1) {
        if (buffer)
            if (read(fd, buffer, size) == -1)
                free(buffer);
        close(fd);
    }
    return (buffer);
}

String_t *getNextLine(int fd, size_t size)
{
    static String_t *buffer = NULL;
    bool find = false;
    char *tmp = NULL;
    
    tmp = malloc(size * sizeof(char));
    while (!find && read(fd, tmp, size) > 0) {
    //    buffer = strCat(buffer, tmp);
     //   if (strLen(buffer) > 0)
      //      free(buffer);
    //    for (size_t i = 0; !find && i < size; i++)
    //        if (buffer[i] == '\n')
    //            find = true;
    }
    free(tmp);
    return (buffer); 
}