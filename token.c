//token.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variable.h"

void tokenize(char* token)
{   
    
            start:
            switch(token[0])//Switch to determine command. 
            {       
               case 'a'://add <val 1> <val 2>
                    if((token[1])&&(token[2]&&!token[3])&&token[1] == 'd'&&token[2] == 'd')
                    {
                           printf("ADD");
                    }
                    else
                    {
                        //printf(token);
                        int varcheck = isvar(token);
                        //printf("%d", varcheck);
                        if(varcheck == 1)
                        {
                           printf("VAR");            
                        }
                        else
                        {
                            printf("Syntax ERROR");
                        }               
                    }
                    break;
               case 'o'://out <var> | <val>
                    if((token[1])&&(token[2]&&!token[3])&&token[1] == 'u'&&token[2] == 't')
                    {
                           printf("OUT");
                    }
                    else
                    {
                        //printf(token);
                        int varcheck = isvar(token);
                        //printf("%d", varcheck);
                        if(varcheck == 1)
                        {
                           printf("VAR");            
                        }
                        else
                        {
                            printf("Syntax ERROR");
                        }               
                    }
                    break;
                 
               case 'v'://var <type> <name>
                    if((token[1])&&(token[2]&&!token[3])&&token[1] == 'a'&&token[2] == 'r')
                    {
                           printf("DVR");
                    }
                    else
                    {
                        //printf(token);
                        int varcheck = isvar(token);
                        //printf("%d", varcheck);
                        if(varcheck == 1)
                        {
                           printf("VAR");            
                        }
                        else
                        {
                            printf("Syntax ERROR");
                        }               
                    }
                    break;
                 
               case 'i'://in <var> <val>
                    if((token[1])&&(!token[2])&&token[1] == 'n')
                    {
                           printf("INV");
                    }
                    else
                    {
                        //printf(token);
                        int varcheck = isvar(token);
                        //printf("%d", varcheck);
                        if(varcheck == 1)
                        {
                           printf("VAR");            
                        }
                        else
                        {
                            printf("Syntax ERROR");
                        }               
                    }
                    break;
               
               case ';'://Devide statments
                    if(!token[1])
                    {
                           printf("ESS");
                    }
                    else
                    {
                        printf("Syntax ERROR");
                    }               
                    break;
               
               case ','://Argument List 
                    if(!token[1])
                    {
                           printf("COM");
                    }
                    else
                    {
                        printf("Syntax ERROR");
                    }               
                    break;
               /* 
               case '-'://Interperter Arguments
                          switch(token[1])
                          {
                                          case 'i':
                                               //Set mode to interpreter
                                               break;
                                          //case 'c';
                          }
                          break;
               case '`'://exit
                    exit(0);
               */
               default:
                       printf("SYNTAX ERROR\n");
                       //nexttoken++;
                       //nexttokenvalue = argv[nexttoken];
                       break;
                           
            }     
}
