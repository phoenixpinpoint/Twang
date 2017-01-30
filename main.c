//main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TwangLib.h"

//TODO Replace with T_STACK adds 
char *value[6];//Temporary Storage Space.
float fvalues[6];//Temporary Float Space. 

int nexttoken = 1;//Initial Token Step. 

int executemode = 0;//Default mode 0 = interpreter. 
//0 = interpreter
//1 = compile to c
//2 = compile to asm



void displayargs(char *args[], int length)
{
     for(int x = 0; x < length; x++)
     {
             printf("%d", x);
             printf(" ");
             printf("%s", args[x]); 
             printf("\n");
     }
}

/*
void interpreter(char *argv[])
{
           
     int argc = strlen(*argv);
     printf("testLang Interpreter\n\n");
            //displayargs(argv, argc);
            printf("\n\nPROGRAM OUTPUT:\n================================\n");
    
            char* token = argv[1];//Intial Token.
            nexttoken++;//Set to 2 as token is set to 1
            char* nexttokenvalue;//Set Value.  
    
            start:
            //printf(token);
            //printf("\n ");
            nexttokenvalue = argv[nexttoken];//Set Value
            //printf(nexttokenvalue);
            switch(token[0])//Switch to determine command. 
            {       
               case 'a'://add <val 1> <val 2>
                          printf("\n---add---\n");
                          value[0] = nexttokenvalue;
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken]; 
                          value[1] = nexttokenvalue; 
                          value[2] =  getval(value[0]);
                          value[3] =  getval(value[1]);
                          fvalues[0] = atof(value[2]);
                          fvalues[1] = atof(value[3]);
                          f_out(add(fvalues[0], fvalues[1]));
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          token = nexttokenvalue;
                          break;
               case 'o'://out <var> | <val>
                          //printf("\n---out---\n");
                          out(nexttokenvalue);
                          nexttoken++;//Skip the arg. 
                          nexttokenvalue = argv[nexttoken];
                          token = nexttokenvalue;
                          break;
               case 'v'://var <type> <name>
                          //printf("\n---var---\n");
                          value[0] = nexttokenvalue;
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          value[1] = nexttokenvalue; 
                          decvar(value[0], value[1]);
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          token = nexttokenvalue;
                          break;
               case 'i'://in <var> <val>
                          //printf("\n---itv---\n");
                          value[0] = nexttokenvalue;
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          value[1] = nexttokenvalue; 
                          in(value[0], value[1]);
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          token = nexttokenvalue;
                          currentvar++;
                          break;
               case ';'://Devide statments
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          //printf("\n---ess---\n");
                          token = nexttokenvalue;
                          nexttoken++;
                          break;
               case ','://Argument List 
                          //Some code for enumerating 
                          break;
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
               default:
                       out("SYNTAX ERROR\n");
                       nexttoken++;
                       nexttokenvalue = argv[nexttoken];
                       break;
                           
            }
            //printf("%d", argc);
            //printf("%d", nexttoken);
            if(nexttoken < argc)
            {
                         goto start;	
                 //printf("\n");      
            }
}
*/
int main(int argc, char *argv[])
{
    if(argc > 1)
    {

            printf("\n\nPROGRAM OUTPUT:\n================================\n");
            char* token = argv[1];//Intial Token.
            nexttoken++;//Set to 2 as token is set to 1
            char* nexttokenvalue;//Set Value.  
            
            char buffer[255];//misc buffer
            int result;//
            
            char *s;
    
            start:
            nexttokenvalue = argv[nexttoken];//Set Value
            switch(token[0])//Switch to determine command. 
            {       
               case 'a'://add <val 1> <val 2>
                    printf("\n---add---\n");
                    value[0] = nexttokenvalue;
                    nexttoken++;
                    nexttokenvalue = argv[nexttoken];
                    value[1] = nexttokenvalue; 
                    value[2] =  displayvar(value[0]);
                    value[3] =  displayvar(value[1]);
                    fvalues[0] = atof(value[2]);
                    fvalues[1] = atof(value[3]);
                    f_out(add(fvalues[0], fvalues[1]));
                    nexttoken++;
                    nexttokenvalue = argv[nexttoken];
                    token = nexttokenvalue;
                    break;
               case 's'://subtract <val 1> <val 2>
                          printf("\n---sub---\n");
                          value[0] = nexttokenvalue;
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          value[1] = nexttokenvalue; 
                          value[2] =  displayvar(value[0]);
                          value[3] =  displayvar(value[1]);
                          fvalues[0] = atof(value[2]);
                          fvalues[1] = atof(value[3]);
                          f_out(sub(fvalues[0], fvalues[1]));
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          token = nexttokenvalue;
                          break;
               case 'd'://divide <val 1> <val 2>
                          printf("\n---div---\n");
                          value[0] = nexttokenvalue;
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          value[1] = nexttokenvalue; 
                          value[2] =  displayvar(value[0]);
                          value[3] =  displayvar(value[1]);
                          fvalues[0] = atof(value[2]);
                          fvalues[1] = atof(value[3]);
                          f_out(divide(fvalues[0], fvalues[1]));
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          token = nexttokenvalue;
                          break;
               case 'm'://multiply <val 1> <val 2>
                          printf("\n---mul---\n");
                          value[0] = nexttokenvalue;
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          value[1] = nexttokenvalue; 
                          value[2] =  displayvar(value[0]);
                          value[3] =  displayvar(value[1]);
                          fvalues[0] = atof(value[2]);
                          fvalues[1] = atof(value[3]);
                          f_out(mul(fvalues[0], fvalues[1]));
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          token = nexttokenvalue;
                          break;
               case 'o'://out <var> | <val>
                          printf("\n---out---\n");
                          out(nexttokenvalue);
                          nexttoken++;//Skip the arg. 
                          nexttokenvalue = argv[nexttoken];
                          token = nexttokenvalue;
                          break;
               case 'v'://var <name> | <value>
                          printf("\n---var---\n");
                          value[0] = nexttokenvalue;
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          declarevar(value[0]);
                          if(value[1] == ";")
                          {
                                      token = nexttokenvalue;
                          }
                          else
                          {
                              value[1] = nexttokenvalue; 
                              definevar(value[0], value[1]);
                              nexttoken++;
                              nexttokenvalue = argv[nexttoken]; 
                              token = nexttokenvalue;          
                          }
                          break;
               /*
               case 'i'://in [operation] [var] <var> <val>
                          printf("\n---itv---\n");
                          value[0] = nexttokenvalue;
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          value[1] = nexttokenvalue; 
                          strcpy(buffer, value[0]);
                          result = strcmp(buffer, "add");
                          if(result == 0)
                          {
                                    nexttoken++;
                                    nexttokenvalue = argv[nexttoken];
                                    value[2] = nexttokenvalue;
                                    fvalues[0] = atof(value[1]);;
                                    fvalues[1] = atof(value[2]);
                                    fvalues[0] = add(fvalues[0], fvalues[1]);
                                    s = (char *) &fvalues[0];
                                    printf(s);
                                    in(value[1], s);        
                          }
                          result = strcmp(buffer, "mul");
                          if(result == 0)
                          {
                                    nexttoken++;
                                    nexttokenvalue = argv[nexttoken];
                                    value[2] = nexttokenvalue;
                                    fvalues[0] = atof(value[1]);;
                                    fvalues[1] = atof(value[2]);
                                    fvalues[0] = mul(fvalues[0], fvalues[1]);
                                    s = (char *) &fvalues[0];
                                    printf(s);
                                    in(value[1], s);        
                          }
                          else
                          {
                              in(value[0], value[1]);
                          }
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          token = nexttokenvalue;
                          currentvar++;
                          break;
               */
               case ';'://Devide statments
                          nexttoken++;
                          nexttokenvalue = argv[nexttoken];
                          printf("\n---ess---\n");
                          token = nexttokenvalue;
                          nexttoken++;
                          break;
               case ','://Argument List 
                          //Some code for enumerating 
                          break;
               case '-'://Interperter Arguments
                          switch(token[1])
                          {
                                          case 'i':
                                               //Set mode to interpreter
                                               break;
                                          //case 'c';
                          }
                          break;
               default:
                       out("SYNTAX ERROR\n");
                       nexttoken++;
                       nexttokenvalue = argv[nexttoken];
                       break;
                           
            }
            //printf("%d", argc);
            //printf("%d", nexttoken);
            if(nexttoken < argc)
            {
             goto start;	
                 //printf("\n");      
            }
    }
    else
    {

                //printf("Enter Code:");
                //printf("\n");
                //char* code[3];
                //scanf("%s", code); 
                //interpreter(code);     
                printf("%d", getvariables_len()); 

    }
    return 0;
}

