#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h> //for the size_t def

#define CHUNCK_SIZE sizeof(chunck); // the size of the chunck

void *head_of_chunck = NULL; // head of linked list

typedef struct Chunck
{
    size_t element;
    struct Chunck *next;
    int free;
} chunck;

chunck *check_free_space(chunck **dernier, size_t element)
{
    chunck *current_chunck = head_of_chunck;
    return current_chunck;
}

int main(int argc, char const *argv[])
{

    return 0;
}
