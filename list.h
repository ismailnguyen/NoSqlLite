#include <stdio.h>
#include <stdlib.h>
#include "hashmap.c"

typedef struct s_list
{
    t_hashmap * value;
    struct s_list * next;
} t_list;

enum remove_mode
{
    FIRST,
    LAST,
    ALL
};

t_list* list_create(t_hashmap * value);
void list_display(t_list* list);

t_list* list_append(t_list* list, t_hashmap * value);
t_list* list_insert(t_list* list, unsigned int index, t_hashmap * value);
t_list* list_remove_index(t_list* list, unsigned int index);
t_list* list_remove_value(t_list* list, enum remove_mode mode, t_hashmap * value);

// WITH DOUBLE POINTER
void list_append2(t_list** list, t_hashmap * value);
void list_insert2(t_list** list, unsigned int index, t_hashmap * value);
void list_remove_index2(t_list** list, unsigned int index);
