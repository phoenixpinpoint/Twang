/*
io.c 
Twang basic I/O library

Keywords:
         in 
         out

Syntax:
       in <var> | <val>
       out <var> | <val>
       f_out <var> | <val>

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variable.h"

void out(char *out)//Output function
{
     
     //printf("variables_len ");
     //printf("%d", getvariables_len());
     //char val1[255];
     //strcpy(val1, out);
     //char val2[255];
     int result;
     for(int x = 0; x<getvariables_len(); x++)
     {       
            //strcpy(val2, varname[x]);
            //result = strcmp(val1,val2);
            //result = 1;
            result = isvar(out);

            if(result == 0)
            {
                       //printf("(");
                       //printf(val2);
                       //printf(")");
                       //displayvar(out);  
                       printf(displayvar(out));
            }
            if(x == getvariables_len() -1 &&  result != 0)
            {
                 printf(out);     
            }
            result = 1;
    } 
}
void f_out(float out)//Output function
{
    printf("%f",out); 
}



void in(char *var, char *value)//Input function
{
    char val1[255];
    strcpy(val1, var);;
    int result = 1;
    for(int x = 0; x<=getvariables_len(); x++)
    {

            //result = strcmp(val1,val2);
            result = isvar(val1);
            //printf(val1);
            //printf("\n");
            //printf(val2);
            //printf("\n");
            //printf("%d", result);
            if(result == 0)
            {
                       definevar(val1 , value);
                       //printf(value);
                       //printf(" ----> ");
                       //printf(val1);
            }            
    }
}
