#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
    ArrayList *list = malloc(sizeof(ArrayList)); 
    list->data = malloc(sizeof(int) * 2);  
    list->size = 0;
    list->capacity = 2;
    return list;
}

void append(ArrayList * l, void * data){
if (l->size == l->capacity) { 
        l->capacity *= 2; 
        l->data = realloc(l->data, sizeof(void*) * l->capacity); 
    }
    l->data[l->size] = data; 
    l->size++; 
}

void push(ArrayList * l, void * data, int i){
    if (i > l->size) { 
        return;
    }
    if (l->size == l->capacity) { 
        l->capacity *= 2; 
        l->data = realloc(l->data, sizeof(void*) * l->capacity); 
    }
 
    for (int j = l->size; j > i; j--) {
        l->data[j] = l->data[j - 1];
    }
    l->data[i] = data; 
    l->size++; 
}

void* pop(ArrayList * l, int i){
    if (i < 0) { 
        i = l->size + i;
    }
    if (i < 0 || i >= l->size) { 
        return NULL;
    }
    return l->data[i]; 
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
