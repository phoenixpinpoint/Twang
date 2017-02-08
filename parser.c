//parser.c
typedef struct {
        char* libname;
        char *tokens[]; 
} library;

library twanglib;
twanglib.libname = "twanglib";
twanglib.tokens = {"out","in", "var", ";"};

library twangmath;
twangmath.libname = "twangmath";
twangmath.tokens ={"add", "sub", "mul", "devide"};

