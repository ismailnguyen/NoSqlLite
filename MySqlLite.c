#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nosqlite.h"

int startsWith(const char *pre, const char *str)
{
    size_t lenpre = strlen(pre),lenstr = strlen(str);
    return lenstr < lenpre ? 0 : strncmp(pre, str, lenpre) == 0;
}

void main (int argc, char **argv)
{
    char * _collection,
            * _insert,
            * _set,
            * _where,
            * _find,
            * _projection,
            * _sort,
            * _remove,
            * _parameters = NULL;

    if(strstr(argv[1], "-collection=") != NULL)
	{
	    char *_parameters = strchr(argv[1], '=') + 1;

	    _collection = malloc(sizeof(char) * strlen(_parameters) + 1);
	    strncpy(_collection, _parameters, strlen(_parameters));
	    _collection[strlen(_parameters)] = '\0';

        //DEBUG
	    printf("collection: %s\n",  _collection);

        if(strstr(argv[2], "-insert") != NULL)
        {
            _parameters = strchr(argv[2], '=') + 1;

            _insert = malloc(sizeof(char) * strlen(_parameters) + 1);
            strncpy(_insert, _parameters, strlen(_parameters));
            _insert[strlen(_parameters)] = '\0';

            //DEBUG
            printf("insert: %s\n",  _insert);
            //JSON_parse(_insert);

        }
        if(strstr(argv[2], "-set") != NULL)
        {
            _parameters = strchr(argv[2], '=') + 1;

            _set = malloc(sizeof(char) * strlen(_parameters) + 1);
            strncpy(_set, _parameters, strlen(_parameters));
            _set[strlen(_parameters)] = '\0';

            //DEBUG
            printf("set: %s\n",  _set);

            if(strstr(argv[3], "-where") != NULL)
            {
                _parameters = strchr(argv[3], '=') + 1;

                _where = malloc(sizeof(char) * strlen(_parameters) + 1);
                strncpy(_where, _parameters, strlen(_parameters));
                _where[strlen(_parameters)] = '\0';

                //DEBUG
                printf("where: %s\n",  _where);
            }
        }
        if(strstr(argv[2], "-find") != NULL)
        {
            _parameters = strchr(argv[2], '=') + 1;

            _find = malloc(sizeof(char) * strlen(_parameters) + 1);
            strncpy(_find, _parameters, strlen(_parameters));
            _find[strlen(_parameters)] = '\0';

            //DEBUG
            printf("find: %s\n",  _find);

            if(strstr(argv[3], "-projection") != NULL)
            {
                _parameters = strchr(argv[3], '=') + 1;

                _projection = malloc(sizeof(char) * strlen(_parameters) + 1);
                strncpy(_projection, _parameters, strlen(_parameters));
                _projection[strlen(_parameters)] = '\0';

                //DEBUG
                printf("projection: %s\n",  _projection);

                if(strstr(argv[4], "-sort") != NULL)
                {
                    char *_parameters = strchr(argv[4], '=') + 1;

                    _sort = malloc(sizeof(char) * strlen(_parameters) + 1);
                    strncpy(_sort, _parameters, strlen(_parameters));
                    _sort[strlen(_parameters)] = '\0';

                    //DEBUG
                    printf("sort: %s\n",  _sort);
            }
            }
        }
        if(strstr(argv[2], "-remove") != NULL)
        {
            _parameters = strchr(argv[2], '=') + 1;

            _remove = malloc(sizeof(char) * strlen(_parameters) + 1);
            strncpy(_remove, _parameters, strlen(_parameters));
            _remove[strlen(_parameters)] = '\0';

            //DEBUG
            printf("remove: %s\n",  _remove);
        }
	}
	//return 0;
}
