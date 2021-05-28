#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX];
    int heap_size;
} HeapType;

HeapType* Create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType *h)
{
    h->heap_size = 0;
}

void Add(HeapType *h, element item)
{
    int index;
    index = ++(h->heap_size);
    
    while((index != 1) && (item.key > h->heap[index/2].key))
    {
        h->heap[index] = h->heap[index/2];
        index /= 2;
    }
    
    h->heap[index] = item; 
}

element Remove(HeapType *h)
{
    int parent, child;
    element item, temp;
    
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    
    while(child <= h->heap_size)
    {
        if((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
            child++;
        if(temp.key >= h->heap[child].key) 
			break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void Destroy(HeapType *h) {
	while(h->heap_size != 0) {
		delete(h->heap);
	}
} 

void IsEmpty(HeapType *h) {
	if(h->heap_size == 0)
		printf("IsEmpty\n");
	else
		printf("NoEmpty\n");
}

int main(int argc, const char * argv[]) {
    HeapType *heap;
    element e1 = {10}, e2 = {5}, e3 = {30}, e4 = {8}, e5 = {34};
    element e6, e7;
    
    heap = Create();
    init(heap);
    
    IsEmpty(heap);
    
    Add(heap, e1);
    Add(heap, e2);
    Add(heap, e3);
    Add(heap, e4);
    Add(heap, e5);

    e6 = Remove(heap);
    printf("%d\n", e6);
    
    e7 = Remove(heap);
    printf("%d\n", e7);
    
    IsEmpty(heap);
    Destroy(heap);
    
    
    return 0;
}

