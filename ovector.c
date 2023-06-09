#include "ovector.h"
#include <stdlib.h>
#include <stdio.h>

int* createArray(int capacity) {
    int* array = malloc(capacity*sizeof(int));
    if(array == NULL){
        printf("Memory allocation for Ovector failed.\n");
    }else{
        return array;
    }
}

void initVector(OVector* vector) {
    vector->size = 0;
    vector->capacity = 5;
    vector->array = createArray(vector->capacity);
}

void deleteArray(OVector* vector) {
    free(vector->array);
    vector->array = NULL;
}

void resizeArray(OVector* vector, int newCapacity) {
    int* newArray = realloc(vector->array, newCapacity * sizeof(int));
    if (newArray != NULL) {
        vector->array = newArray;
        vector->capacity = newCapacity;
    }else
        printf("capacity is 0");
}

void sizeIncrement(OVector* vector){
    if (vector->size == vector->capacity) {
        resizeArray(vector, vector->capacity * 2);
    }
}

void pushBack(OVector* vector, int element) {
    sizeIncrement(vector);
    vector->array[vector->size++] = element;
}

void pushFront(OVector* vector, int element) {
    sizeIncrement(vector);
    for (int i = vector->size; i >= 0; i--) {
        vector->array[i] = vector->array[i - 1];
    }
    vector->array[0] = element;
    vector->size++;
}

void popBack(OVector* vector ) {
    if(vector->size > 0){
        vector->size--;
    }
}

void popFront(OVector* vector ) {
    if(vector->size > 0){
        for (int i = 0; i < vector->size; i++) {
            vector->array[i] = vector->array[i + 1];
        }
        vector->size--;
    }

}

void clear(OVector* vector) {
    vector->size = 0;
    resizeArray(vector, 5);
}

void removeElem(OVector* vector, int index) {
    if (index >= 0 && index < vector->size) {
        for (int i = index; i < vector->size - 1; i++) {
            vector->array[i] = vector->array[i + 1];
        }
        vector->size--;
    }
}

void show(OVector* vector) {
    printf("\n{ ");
    for (int i = 0; i < vector->size; i++) {
        printf("%d ",vector->array[i]);
    }
    printf("}\n");
}
