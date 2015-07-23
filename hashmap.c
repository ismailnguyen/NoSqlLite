#include "hashmap.h"

/*int main()
{
	t_hashmap* map = hashmap_create(100, 0.7, 2.1);
	//t_hashmap_entry* entry = hashmap_entry_create("Bonjour", "hashmap");
	hashmap_put(map, "Bonjour", "hashmap");
	hashmap_put(map, "Aurevoir", "prout");

	hashmap_display(map);
	system("pause");
	return 0;
}
*/
t_hashmap* hashmap_create(unsigned int slots, double load_factor, double growth_factor)
{
	t_hashmap* map = (t_hashmap*)malloc(sizeof(t_hashmap));
	map->load_factor = load_factor;
	map->growth_factor = growth_factor;
	map->initial_slots = slots;
	map->slots = slots;
	map->size = 0;

	map->entry = (t_hashmap_entry**)malloc(sizeof(t_hashmap_entry*)*slots);

	int i = 0;
	for(; i < slots; i++)
		map->entry[i] = NULL;

	return map;
}

t_hashmap_entry* hashmap_entry_create(char *key, void *value)
{
	t_hashmap_entry* entry = (t_hashmap_entry*)malloc(sizeof(t_hashmap_entry));
	entry->key = key;
	entry->value = value;
	entry->next = NULL;

	return entry;
}

void hashmap_display(t_hashmap* map)
{
	unsigned int i = 0;
	t_hashmap_entry* tmp;
	while(i < map->slots)
	{
		tmp = map->entry[i];
		while(tmp != NULL)
		{
			printf("%s -> %s\n", tmp->key, tmp->value);
			tmp = tmp->next;
		}
		i++;
	}
}
unsigned int hashmap_hash(char* key, unsigned int slots)
{
	unsigned int hashcode = 1069;
	while(*key)
	{
		hashcode += *(key++);
	}

	return hashcode % slots;
}

/*t_hashmap_keys* hashmap_keys(t_hashmap* map)
{
	t_hashmap_keys* hkeys = (t_hashmap_keys*)malloc(sizeof(t_hashmap_keys));

	hkeys->keys = (char**)malloc(sizeof(char*)*hashmap->size);

	unsigned int i = 0;
	while(i < map->slots)
	{
		if(map->entry[i]->key)
			hkeys->keys[i]
		i++;
	}
}*/

t_hashmap_keys* hashmap_keys(t_hashmap* map)
{
	t_hashmap_keys* hkeys = (t_hashmap_keys*)malloc(sizeof(t_hashmap_keys));

	hkeys->keys = (char**)malloc(sizeof(char*)*map->size);

	unsigned int i = 0;
	unsigned int keyCount = 0;
	t_hashmap_entry* entry_set;

	for(i = 0; i < map->slots; i++)
	{
		entry_set = map->entry[i];
		while(entry_set)
		{
			strcpy(hkeys->keys[keyCount], entry_set->key);
			keyCount++;
			hkeys->lenght = keyCount;
			entry_set = entry_set->next;
		}
	}

	return hkeys;
}


void hashmap_put(t_hashmap* map, char* key, void* value)
{
	if( map->size >= map->slots * map->load_factor)
	{
		//hashmap_expand(map);
	}

	unsigned int hash = hashmap_hash(key, map->slots);
	unsigned short found = 0;

	t_hashmap_entry** entry = &(map->entry[hash]);

	while(*entry)
	{
		if( 0 == strcmp(key, (*entry)->key))
		{
			(*entry)->value = value;
			found = 1;
			break;
		}
		entry = &(*entry)->next;
	}

	if(!found)
	{
		map->size++;
		*entry = hashmap_entry_create(key, value);
	}
}

void* hashmap_get(t_hashmap* map, char* key)
{
	unsigned int hash = hashmap_hash(key, map->slots);
	t_hashmap_entry* entry = map->entry[hash];
	while(entry)
	{
		if(!strcmp(key, entry->key))
			return entry->value;
		entry = entry->next;
	}
	return NULL;
}

void hashmap_expand(t_hashmap* map)
{
	unsigned int i = map->slots;
	t_hashmap_entry** entry = map->entry;

	map->slots *= map->growth_factor;
	map->size = 0;
	map->entry = (t_hashmap_entry**)calloc(map->slots, sizeof(t_hashmap_entry*));
	t_hashmap_entry *prev, *element;
	while(i--)														// Parcours de la liste contigue
	{
		element = entry[i];
		while(element)												// Parcours de la liste chaînée
		{
			hashmap_put(map, element->key, element->value);			// Recopie l'élément
			prev = element;
			element = element->next;
			free(prev);
		}
	}
	free(entry);
}

void hashmap_remove(t_hashmap* map, char* key)
{
	unsigned int hash = hashmap_hash(key, map->slots);
	t_hashmap_entry* tmp = NULL;
	t_hashmap_entry** entry = &map->entry[hash];
	while(*entry)
	{
		if(strcmp(key, (*entry)->key))
		{
			tmp = *entry;
			*entry = (*entry)->next;
			free(tmp);
			map->size--;
			break;
		}
		entry = &(*entry)->next;
	}
}
