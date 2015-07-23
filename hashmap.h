#include <stdio.h>
#include <stdlib.h>

typedef struct s_hashmap_entry
{
    char* key;
    char* value;
    struct s_hashmap_entry* next;
} t_hashmap_entry;

typedef struct s_hashmap
{
    int slots; //size of the list
    int size; //number of elements
    float load_factor;
    float grow_factor;
    t_hashmap_entry** entries;
} t_hashmap;


t_hashmap* hashmap_create(int slots, float load_factor, float grow_factor);
t_hashmap_entry* hashmap_entry_create(char* k, char* v);
char* hashmap_get(t_hashmap* map, char* k);
void hashmap_remove(t_hashmap* map, char* k);

//JSON parser
t_hashmap* JSON_parse(char* string); //Convert a JSON String to a HashMap representation
char* JSON_stringify(t_hashmap* map); //Convert a HashMap to a JSON String representation
void* hashmap_traverse(t_hashmap*map, char* path); // Traverse a HashMap according to the given path
// Ex :  hashmap_traverse(map, 'student.rate')
void hashmap_put(t_hashmap*map, char* path, void* value); // Traverse a HashMap according to the given path
// Ex :  hashmap_put(map, 'student.rate', 56);
//       hashmap_traverse(map, 'student.rate')   56
