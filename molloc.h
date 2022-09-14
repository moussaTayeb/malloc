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

#endif // MOLLOC_H_