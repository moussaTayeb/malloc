#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h> //for the size_t def

#define CHUNCK_SIZE sizeof(struct Chunck) // the size of the chunck, !!!! dont add ;

void *head_of_chunck = NULL; // head of linked list

typedef struct Chunck
{
    size_t element;
    struct Chunck *next;
    int free;
    int debug;
} chunck;

chunck *check_free_space(chunck **dernier, size_t element)
{
    chunck *current_chunck = head_of_chunck;
    if (current_chunck && !(current_chunck->free && current_chunck->element >= element))
    {
        *dernier = current_chunck;
        current_chunck = current_chunck->next;
    }
    return current_chunck;
}

chunck *get_free_space(chunck *dernier, size_t element)
{
    chunck *block_mem;
    block_mem = sbrk(0);
    void *request = sbrk(CHUNCK_SIZE + element);
    assert((void *)block_mem == request);
    if (request == (void *)-1)
    {
        return NULL;
    }
    if (dernier)
    {
        dernier->next = block_mem;
    }
    block_mem->element = element;
    block_mem->next = NULL;
    block_mem->free = 0;
    block_mem->debug = 0x11111111;
    return block_mem;
}

// TODO: implement ->

void *malloc(size_t element)
{
    
}
int main(int argc, char const *argv[])
{

    return 0;
}
