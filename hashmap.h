#include <stdio.h>
#include <stdlib.h>

typedef struct s_hashmap_entry
{
    char* key;
    void* value;
    struct s_hashmap_entry* next;
} t_hashmap_entry;

typedef struct hashmap_keys
{
    char* keys;
    unsigned int length;
} t_hashmap_keys;

typedef struct s_hashmap
{
    double load_factor; //taux de remplissage max
    double growth_factor; //taux d’expension longue load factor atteint
    unsigned int initial_slots; //taille initiale de tableau
    unsigned int slots; //taille actuelle du tableau
    unsigned int size; //nb entrées dans la map
    t_hashmap_entry** entries; //le tableau
} t_hashmap ;

void hash_map_display(t_hashmap map);
t_hashmap * hashmap_create(unsigned int slots, double load_float, double growth_factor);
t_hashmap_entry * hashmap_entry_create(char* key, void* value);
void hashmap_put(t_hashmap * map, char* key, void* value);
void hashmap_remove(t_hashmap * map, char* key);
void * hashmap_get(t_hashmap * map, char* key);
t_hashmap_keys * hasmap_key(t_hashmap * map);
void hashmap_expand(t_hashmap * map);
unsigned int hashmap_hash(char* key, int slots);

//JSON parser
t_hashmap* JSON_parse(char* string); //Convert a JSON String to a HashMap representation
char* JSON_stringify(t_hashmap* map); //Convert a HashMap to a JSON String representation
void* hashmap_traverse(t_hashmap*map, char* path); // Traverse a HashMap according to the given path
// Ex :  hashmap_traverse(map, 'student.rate')
void hashmap_put(t_hashmap*map, char* path, void* value); // Traverse a HashMap according to the given path
// Ex :  hashmap_put(map, 'student.rate', 56);
//       hashmap_traverse(map, 'student.rate')   56
