#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct s_hashmap_entry
{
	char* key;
	void* value;
	struct s_hashmap_entry* next;
} t_hashmap_entry;

typedef struct s_hashmap
{
	double load_factor;				// Taux de remplissage maximum
	double growth_factor;			// Taux d'expansion lorsque remplissage max atteind
	unsigned int initial_slots;		// Taille initial du tableau
	unsigned int slots;				// Taille actuelle du tableau
	unsigned int size;				// Nombre d'entrée dans la map
	t_hashmap_entry** entry;		// Tableau
} t_hashmap;

typedef struct s_hashmap_keys
{
	char** keys;
	unsigned int lenght;
}t_hashmap_keys;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Création la hashmap : Initialiser la structure et affecter NULL à toutes les valeurs du tableau entry
t_hashmap* hashmap_create(unsigned int slots, double load_factor, double growth_factor);

void hashmap_display(t_hashmap* map);

// Ajout d'un élément
t_hashmap_entry* hashmap_entry_create(char *key, void *value);

// Fonction de hashage
unsigned int hashmap_hash(char* key, unsigned int slots);

// Si size < slots * load_factor
// Calcul du hash et de l'indice
// Si clé existe :
//		Si non : Mise à jour de la valeur
//		Si non : Ajout de l'entrée dans la liste chainée
void hashmap_put(t_hashmap* map, char* key, void* value);
void hashmap_remove(t_hashmap* map, char* key);
void* hashmap_get(t_hashmap* map, char* key);
t_hashmap_keys* hashmap_keys(t_hashmap* map);

//JSON parser
t_hashmap* JSON_parse(char* string); //Convert a JSON String to a HashMap representation
char* JSON_stringify(t_hashmap* map); //Convert a HashMap to a JSON String representation
void* hashmap_traverse(t_hashmap*map, char* path); // Traverse a HashMap according to the given path
// Ex :  hashmap_traverse(map, 'student.rate')
void hashmap_put(t_hashmap*map, char* path, void* value); // Traverse a HashMap according to the given path
// Ex :  hashmap_put(map, 'student.rate', 56);
//       hashmap_traverse(map, 'student.rate')   56

#endif // HASHMAP_H
