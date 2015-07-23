#include "hashmap.h"

void hash_map_display(t_hashmap * map)
{
    unsigned int i = 0;
    t_hashmap_entry* tmp;
    while(i<map->slots)
    {
        tmp = map->entries[i];

        while(tmp != NULL)
        {
            printf("%s -> %s\n", tmp->key, tmp->value);
            tmp = tmp->next;
        }

        i++;
    }
}

/*
* initialiser la structure et affecter NULL à toutes les valeurs du tableau entries
*/
t_hashmap * hashmap_create(unsigned int slots, double load_float, double growth_factor)
{
	t_hashmap * dico = (t_hashmap)malloc(sizeof(t_hashmap));
	dico->load_float = load_float;
	dico->growth_factor = growth_factor;

	int i;

	for(i=0; i<slots; i++)
	{
		dico->entries[i] = NULL;
	}

	return dico;
}


t_hashmap_entry * hashmap_entry_create(char* key, void* value)
{
	t_hashmap_entry * entry = (t_hashmap *)malloc(sizeof(t_hashmap_entry);

	entry->value = value;
	entry->key = key;
	entry->next = NULL;

	return entry;
}

void hashmap_put(t_hashmap * map, char* key, void* value)
{
	if(map->size >= map->slots*map->load_float)
	{
		//hashmap_expand(map);
	}

	unsigned int hash = hashmap_hash(key, map->slot);
	unsigned int short found = 0;
	t_hashmap_entry ** entry =&(map->entry[hash]);

	while(*entry)
	{
		if(0 == strcmp(key, (*entry)->key))
		{
			(*entry)->value = value;
			found = 1;
			break;
		}
		entry =&(*entry)->next;
	}

	if(!found)
	{
		map->size++;
		*entry = hashmap_create_entry(key, value);
	}
}

void hashmap_remove(t_hashmap * map, char* key)
{
	unsigned int hash = hashmap_hash(key, map->slot);
	t_hashmap_entry * tmp;
	t_hashmap_entry** entry =&map->entry[hash];

	while(*entry)
	{
		if(!strcmp(key, (*entry)->key))
		{
			tmp = *entry;
			*entry = (*entry)->next;
			free(tmp);
			map->size--;
			break;
		}
		entry =&(*entry)->next;
	}
}

void * hashmap_get(t_hashmap * map, char* key)
{
	unsigned int hash = hashmap_hash(key, map->slot);
	t_hashmap_entry * entry = map->entry[hash];

	while(entry)
	{
		if(!strcmp(key, entry->key))
			return entry->value;
		entry = entry->next;
	}

	return NULL;
}

t_hashmap_keys * hasmap_key(t_hashmap * map)
{
	int i;
    int keyCount = 0;
    t_hashmap_entry* entry_set;
    t_hashmap_keys* hk = (t_hashmap_keys*)malloc(sizeof(t_hashmap_keys));
    hk->keys = (char**)malloc(sizeof(char*)*map->size);

    for(i=0; i<map->slots; i++)
    {
        entry_set = map->entries[i];

        while(entry_set)
        {
            hk->key[key_count] = strcpy(entry_set[key]);
            key_count++;
            hk->length = key_count;
            entry_set = entry_set->next;
        }
    }

    return hk;
}

void hashmap_expand(t_hashmap * map)
{
	unsigned int i = map->slot;
	t_hashmap_entry ** entry = map->entry;

	map->slot *= map->growth_factor;
	map->size = 0;
	map->entry = (t_hashmap_entry**)calloc(map->slot, sizeof(t_hashmap_entry*));
	t_hashmap_entry * prev, * element;

	while(i--) //parcours de la liste contigue
	{
		element = entry[i];
		while(element) //parcours de la liste chainee
		{
			hashmap_put(map, element->key, element->value);
			// recopie l'élement
			prev = element;
			element = element->next;

			free(prev); //libère l'élement de l'ancienne liste chainée
		}
	}
	free(entry); //libère l'ancienne liste contigue
}

unsigned int hashmap_hash(char* key, int slots)
{
	unsigned int hash = 1063;
	while(*key)
			hash += *(key++);
	return hash%slot;
}
