#include <stdlib.h>
#include <stdio.h>
#include "dsa_1_hashmap.h"

HashMap *HM_create(int size){
    HashMap *res = (HashMap *)malloc(sizeof(HashMap));
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL || res == NULL) {
        printf("Memory not allocated.\n");
        exit(1);
    }
    res->size = size;
    res->list = arr;
    return res;
}

static int hashCode(HashMap *t, int key){
    if (key < 0)
        return -(key % t->size);
    return key % t->size;
}

void HM_insert(HashMap *map, int key, int value){
    int hash = hashCode(map, key);
    map->list[hash] = value;
}

void HM_remove(HashMap *map, int key){
    int hash = hashCode(map, key);
    map->list[hash] = 0;
}

int HM_lookup(HashMap *map, int key){
    int hash = hashCode(map, key);
    return map->list[hash];
}

void HM_free(HashMap *map){
    free(map->list);
    free(map);
};