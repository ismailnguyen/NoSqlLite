#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

t_hashmap* hashmap_create(int slots, float load_factor, float grow_factor){
    t_hashmap* hashmap = (t_hashmap*)malloc(sizeof(t_hashmap));
    hashmap->slots = slots;
    hashmap->load_factor = load_factor;
    hashmap->grow_factor = grow_factor;
    hashmap->size = 0;
    hashmap->entries = (t_hashmap_entry**)malloc(sizeof(struct t_hashmap_entry)*slots);
    return hashmap;
}

t_map_entry* map_entry_create(char*k, char*v){
    t_hashmap_entry* entry = (t_hashmap_entry*)malloc(sizeof(t_hashmap_entry));
    entry->key = k;
    entry->value = v;
    entry->next = NULL;
    return entry;
}

char* indice_result(char* k, int indice){
    int keyint = (int)k;
    int result = keyint%indice;
    char* result_indice = (char*)result;
    return result_indice;
}

void hashmap_put(t_hashmap* hashmap, char*k, char* v){
    if (!hashmap)return;
    int hashcode = 0;
    for (int i = 0; i < strlen(k); ++i) {
        hashcode += k[i];
    }
    if (!hashmap->entries[hashcode%hashmap->slots]){
        hashmap->entries[hashcode%hashmap->slots]= hashmap_entry_create(k,v);
    }else{
        t_hashmap_entry* entry = hashmap->entries[hashcode%hashmap->slots];
        while (&entry){
            entry=entry->next;
        }
        entry=hashmap_entry_create(k,v);
    }
}
char* hashmap_get(t_hashmap* hashmap, char* k){
    int hashcode = 0;
    for (int i = 0; k[i]; ++i) {
        hashcode +=k[i];
    }
    t_hashmap_entry* current = hashmap->entries[hashcode%hashmap->slots];
    while (current){
        if (strcmp(current->key,k)==0)
            return current->value;
        current = current->next;
    }
    return NULL;
}

void hashmap_put2(t_hashmap* hashmap, char*k, char*v){
    int hashcode = 0;
    for (int i = 0; k[i]; ++i) {
        hashcode +=k[i];
    }
    t_hashmap_entry** current = &hashmap->entries[hashcode%hashmap->slots];
    while (*current){
        if (strcmp((*current)->key, k)==0){
            (*current)->value = v;
            return;
        }
        current = &(*current)->next;
    }
    *(current) = hashmap_entry_create(k,v);
}

void hashmap_delete2(t_hashmap* hashmap, char* k){
    int hashcode = 0;
    for (int i = 0; k[i]; ++i) {
        hashcode +=k[i];
    }
    t_hashmap_entry** current = &hashmap->entries[hashcode%hashmap->slots];
    while (*current){
        if (strcmp((*current)->key, k)==0){
            t_hashmap_entry* tmp = *current;
            *current = (*current)->next;
            free(tmp);
        }
    }
}
void hashmap_delete(t_hashmap* hashmap, char* k){
    int hashcode = 0;
    for (int i = 0; k[i]; ++i) {
        hashcode +=k[i];
    }
    t_hashmap_entry* current = hashmap->entries[hashcode%hashmap->slots];
    t_hashmap_entry* previous = current;
    if (current&& strcmp(current->key, k)==0){
        t_hashmap_entry* temp = current;
        hashmap->entries[hashcode%hashmap->slots]= temp->next;
        free(temp);
    }
    while (current){
        if (strcmp(current->key, k)==0){
            previous->next = current->next;
            free(current);
        }
        else {
            previous = current;
        }
        current = previous->next;
    }
}
