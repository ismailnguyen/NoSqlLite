#include "file.h"
#include "list.h"

void file_display(char filename)
{
   char ch, file_name[25];
   FILE *fp;

   printf("Enter the name of file you wish to see\n");
   gets(file_name);

   fp = fopen(file_name,"r"); // read mode

   if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   printf("The contents of %s file are :\n", file_name);

   while( ( ch = fgetc(fp) ) != EOF )
      printf("%c",ch);

   fclose(fp);
}

void file_write(FILE** dest, t_list* list)
{
    if (list != NULL)
    {
        int intval;
        double doubleval;

        fprintf(dest, "%s:", list->key);

        if(list->type == INT_TYPE)
        {
            memcpy(&intval,list->value, sizeof(int));
            fprintf(file,"%d", intval);
        }
        else if(list->type == DOUBLE_TYPE)
        {
            memcpy(&doubleval,list->value, sizeof(double));
            fprintf(file,"%lf", doubleval);
        }
        else if(list->type == STRING_TYPE)
        {
            fprintf(file,"'%s'",list->value);
        }
    }
}
