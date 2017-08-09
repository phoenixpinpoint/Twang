/*
Variable.c 
Twang Variable Structure and Functions
Keywords:
         var

Syntax:
       var := var <name> <eos>
       var := var <name> <value> <eos> 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

//declarevar and definevar split. 

typedef struct {
       char* name;
       char* value;
}variable;

int variables_len = 0;

variable vars[0]; 

variable *increasevarsbyone(variable *variables, int size)
{
         variable placeholder[size];
         for(int i = 0; i < size; i++)
         {
               placeholder[i] = variables[i];
         }
         free(variables);
         return placeholder;   
}

void declarevar(char* name)
{
     ////Add var
     if(variables_len == 0)
     {
         variable placeholder = {name, NULL};
         vars[variables_len] = placeholder;
         variables_len++;
         
     }
     else
     {
         *increasevarsbyone(vars, variables_len);
         variable placeholder = {name, NULL};
         vars[variables_len] = placeholder;
         //printf(vars[variables_len].name);
         variables_len++;
     }
     //variable * varpointer = vars;
     //printf("%d", sizeof(varpointer));
     //printf("%d", variables_len);
}
void definevar(char* name, char* value)
{
     for (int x = 0; x < variables_len; x++)
     {
              char var[255];
              int result = 1;
              strcpy(var, name);
              result = strcmp(var,vars[x].name);
              if(result == 0)
              {
                        vars[x].value = value;
                        //printf(vars[x].name);
                        //printf(vars[x].value);
              }   
     }  
}
void removevar()
{
     //Remove var
}

void displayvars()
{
     printf("Variable Table Dump: ");
     printf("\n");
     for (int x = 0; x < variables_len; x++)
     {
                    printf("-----------");
                    printf("\n");
                    printf("%d", x);
                    printf(" : ");
                    printf(vars[x].name);
                    printf(" : ");
                    printf(vars[x].value);
                    printf("\n");     
     }     
}

char* displayvar(char* name)
{
    for(int x = 0; x<variables_len; x++)
    {
            //printf(name);
            if(strcmp(vars[x].name, name)  == 0)
            {
                       return vars[x].value;
            }       
    }
}

int isvar(char* value)
{
    for(int x = 0; x<variables_len; x++)
    {
            //printf(vars[x].name);
            //printf(" : ");
            //printf(value);
            //printf("\n");
            if(strcmp(vars[x].name, value) == 0)
            {
                       return 1;
            }        
            //else{return 0;}
    }
    return 0;
}

int getvariables_len()
{
    return variables_len;   
}

