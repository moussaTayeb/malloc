#ifndef MOLLOC_H_
#define MOLLOC_H_
#include <stddef.h>

typedef struct Chunck
{
    size_t size;
    struct Chunck *next;
    int free;
} chunck;

chunck *check_free_space();

chunck *check_free_space(chunck **dernier, size_t element);
chunck *get_free_space(chunck *dernier, size_t element);
void *malloc(size_t element);

#endif // MOLLOC_H_