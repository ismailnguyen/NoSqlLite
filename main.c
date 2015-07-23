#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
//#include "nosqlite.h"

int startsWith(const char *pre, const char *str)
{
    size_t lenpre = strlen(pre),lenstr = strlen(str);
    return lenstr < lenpre ? 0 : strncmp(pre, str, lenpre) == 0;
}

void main (int argc, char **argv)
{
    char * _collection, * _insert, * _set, * _find, * _remove, * parameters = NULL;

    if(strstr(argv[1], "-collection=") != NULL)
	{
	    parameters = strchr(argv[1], '=') + 1;

	    _collection = malloc(sizeof(char) * strlen(parameters) + 1);
	    strncpy(_collection, parameters, strlen(parameters));
	    _collection[strlen(parameters)] = '\0';

	    printf("collection name: %s\n",  _collection);

	if(strstr(argv[2], "-insert") != NULL)
	{
	    parameters = strchr(argv[2], '=') + 1;

	    _insert = malloc(sizeof(char) * strlen(parameters) + 1);
	    strncpy(_insert, parameters, strlen(parameters));
	    _insert[strlen(parameters)] = '\0';

	    printf("insert values: %s\n",  _insert);
	}
	if(strstr(argv[2], "-set") != NULL)
	{
	}
	if(strstr(argv[2], "-find") != NULL)
	{
	    if(strstr(argv[2], "-projection") != NULL)
	    {

	    }
	}
	if(strstr(argv[2], "-remove") != NULL)
	{
	}
	}
	//return 0;
}
