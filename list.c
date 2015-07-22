#include "list.h"

int main()
{
	// t_list* list = list_create(12);
	// list->next = list_create(3);
	// list->next->next = list_create(25);
	// list_display(list); // 12,3,25

	// t_list* list2 = NULL;
	// list2 = list_append(list2, 13);
	// list2 = list_append(list2, 18);
	// list2 = list_append(list2, 25);
	// list_display(list2); // 13,18,25

	// t_list* list3 = NULL;
	// list3 = list_insert(list3, 0, 18);
	// list3 = list_insert(list3, 1, 12);
	// list3 = list_insert(list3, 1, 25);
	// list3 = list_insert(list3, 0, 13);
	// list_display(list3); // 13,18,25,12

	// t_list* list4 = NULL;
	// list4 = list_append(list4, 10);
	// list4 = list_append(list4, 16);
	// list4 = list_append(list4, 10);
	// list4 = list_append(list4, 16);
	// list4 = list_remove_value(list4, FIRST, 16);
	// list_display(list4); // 10,10,16

	// t_list* list5 = NULL;
	// list5 = list_append(list5, 16);
	// // list5 = list_append(list5, 16);
	// list5 = list_append(list5, 10);
	// // list5 = list_append(list5, 16);
	// list5 = list_append(list5, 10);
	// // list5 = list_append(list5, 16);
	// list5 = list_remove_value(list5, LAST, 16);
	// list_display(list5); // 10,16,10

	// t_list* list6 = NULL;
	// list6 = list_append(list6, 16);
	// list6 = list_append(list6, 16);
	// list6 = list_append(list6, 16);
	// list6 = list_append(list6, 16);
	// list6 = list_append(list6, 10);
	// list6 = list_append(list6, 16);
	// list6 = list_append(list6, 16);
	// list6 = list_append(list6, 10);
	// list6 = list_append(list6, 16);
	// list6 = list_append(list6, 16);
	// list6 = list_append(list6, 16);
	// list6 = list_remove_value(list6, ALL, 16);
	// list_display(list6); // 10,10

	// t_list* list7 = NULL;
	// list7 = list_append(list7, 10);
	// list7 = list_append(list7, 16);
	// list7 = list_append(list7, 10);
	// list7 = list_append(list7, 16);
	// list7 = list_remove_index(list7, 1);
	// list_display(list7); // 10,10,16

	// t_list* list8 = NULL;
	// list8 = list_append(list8, 10);
	// list8 = list_append(list8, 16);
	// list8 = list_append(list8, 10);
	// list8 = list_append(list8, 16);
	// list8 = list_remove_index(list8, 0);
	// list_display(list8); // 16,10,16

	// t_list* list9 = NULL;
	// list9 = list_append(list9, 10);
	// list9 = list_append(list9, 16);
	// list9 = list_append(list9, 10);
	// list9 = list_append(list9, 16);
	// list9 = list_remove_index(list9, 3);
	// list_display(list9); // 10,16,10

	// t_list* list10 = NULL;
	// list10 = list_append(list10, 16);
	// list10 = list_append(list10, 10);
	// list10 = list_append(list10, 10);
	// list10 = list_remove_value(list10, LAST, 16);
	// list_display(list10); // 10,16,10

	t_list* list11 = NULL;
	list_append2(&list11, 13);
	list_append2(&list11, 18);
	list_append2(&list11, 25);
	list_display(list11); // 13,18,25

	t_list* list12 = NULL;
	list_insert2(&list12, 0, 18);
	list_insert2(&list12, 1, 12);
	list_insert2(&list12, 1, 25);
	list_insert2(&list12, 0, 13);
	list_display(list12); // 13,18,25,12
	return 0;
}


t_list* list_create(int value)
{
	t_list* list = (t_list_chain*)malloc(sizeof(t_list));
	list->value = value;
	list->next = NULL;
	return list;
}


void list_display(t_list* list)
{
	if (NULL != list)
	{
		for (; NULL != list->next; list = list->next)
		{
			printf("%i,", list->value);
		}
		printf("%i\n", list->value);
	}
}


t_list* list_append(t_list* list, t_hashmap * value)
{
	t_list* new_node = list_create(value);

	if (NULL == list)
	{
		return new_node;
	}

	t_list* tmp;
	for (tmp = list; NULL != tmp->next; tmp = tmp->next);
	tmp->next = new_node;

	return list;
}


t_list* list_insert(t_list* list, unsigned int index, t_hashmap * value)
{
	t_list* new_node = list_create(value);

	if (NULL == list)
	{
		return 0 == index ? new_node : list;
	}

	if (0 == index)
	{
		new_node->next = list;

		return new_node;
	}

	t_list* tmp;

	for (tmp = list; NULL != tmp->next && --index; tmp = tmp->next);

	new_node->next = tmp->next;
	tmp->next = new_node;

	return list;
}


t_list* list_remove_index(t_list* list, unsigned int index)
{
	if (NULL != list)
	{
		t_list* prev_node;

		// delete the first element
		if (0 == index)
		{
			prev_node = list->next;
			free(list);
			list = prev_node;
		}
		else
		{
			for (prev_node = list; NULL != prev_node->next && --index; prev_node = prev_node->next);

			if (0 == index)
			{
				// delete a middle element
				if (NULL != prev_node->next)
				{
					t_list* next_node = prev_node->next->next;
					free(prev_node->next);
					prev_node->next = next_node;
				}
				// delete the last element
				else
				{
					prev_node->next = NULL;
				}
			}
		}
	}

	return list;
}

t_list* list_remove_value(t_list* list, enum remove_mode mode, t_hashmap * value)
{
	if (NULL != list)
	{
		if (LAST != mode)
		{
			t_list* prev_node;
			t_list* current_node;

			for (prev_node = NULL, current_node = list; NULL != current_node; prev_node = current_node, current_node = current_node->next)
			{
				if (value == current_node->value)
				{
					// if (NULL != prev_node)
					if (list != current_node)
					{
						prev_node->next = current_node->next;
						free(current_node);
						current_node = prev_node;
					}
					else
					{
						list = current_node->next;
						free(current_node);
					}

					if (FIRST == mode)
					{
						break;
					}
				}
			}
		}
		else
		{
			unsigned int found = 0;
			t_list* prev_found_node = NULL;
			t_list* prev_node;
			t_list* current_node;

			for (prev_node = NULL, current_node = list; NULL != current_node; prev_node = current_node, current_node = current_node->next)
			{
				if (value == current_node->value)
				{
					found = 1;
					prev_found_node = prev_node;
				}
			}

			if (1 == found)
			{
				if (NULL != prev_found_node)
				{
					current_node = prev_found_node->next;
					prev_found_node->next = current_node->next;
					free(current_node);
				}
				else
				{
					list = list->next;
					free(current_node);
				}
			}
		}
	}

	return list;
}

void list_append2(t_list** list, t_hashmap * value)
{
	while (NULL != *list)
	{
		list = &(*list)->next;
	}
	*list = list_create(value);
}

void list_insert2(t_list** list, unsigned int index, t_hashmap * value)
{
	while(*list && index)
	{
		list = &(*list)->next;
		index--;
	}

	if(index==0)
	{
		t_list * temp = *list;
		*list = list_create(value);
		(*list)->next = tmp;
	}
}

void list_remove_index2(t_list** list, unsigned int index)
{
	while(*list && index>0)
	{
		list = &(*list)->next;
		index--;
	}

	if()
}
