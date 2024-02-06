#ifndef DSA_1_DS_H
#define DSA_1_DS_H

typedef struct{
    int size;
    int *list;
} HashMap;

HashMap *HM_create(int size);
void HM_insert(HashMap *map, int key, int value);
void HM_remove(HashMap *map, int key);
int HM_lookup(HashMap *map, int key);
void HM_free(HashMap *map);

#endif //DSA_1_DS_H
