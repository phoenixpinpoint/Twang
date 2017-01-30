//t_stack.c

int valuelen = 0;
int fvaluelen = 0;

typedef struct {
       char* value;
}value;

typedef struct {
       float f_value;
}f_value;

value values[0];
f_value f_values[0];

value addvalue(char* value){/*value placeholder[valuelen+1]; placeholder = vavlues; placeholder[valuelen].value = value; valuelen++;*/}

f_value addfvalue(float value){f_values[fvaluelen].f_value = value; fvaluelen++;}

char* getvalue(int index)
{
     for(int x = 0; x < valuelen; x++)
     {
             if(x == index)
             {
                      return values[x].value; 
             }        
     }    
}

float getfvalue(int index)
{
     for(int x = 0; x < fvaluelen; x++)
     {
             if(x == index)
             {
                      return f_values[x].f_value; 
             }        
     }    
}

/*
void removevalue(int index)
{
     for(int x = 0; x < valuelen; x++)
     {
             if(x == index)
             {
                      values[x] = NULL; 
             }        
     }    
}

void removefvalue(int index)
{
     for(int x = 0; x < fvaluelen; x++)
     {
             if(x == index)
             {
                      return f_values[x]; 
             }        
     }    
}
*/

void clearvstack()
{
     int valuelen = 0;
}

void clearfstaci()
{
     int fvaluelen = 0;
}



