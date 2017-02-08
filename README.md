## Welcome to Twang

Twang is a project to build a simplified compiled language for robotics programming. 


### The Goal

The goal is to create a language that compiles to C. Which then can be compiled to the architecture in which your embeded code will run. This allows us to use pre-existing C compilers that are written for any architecture from x86 to ARM64. Thus the user only has to write in one uniform coding language without having to learn C. 

### The Process

The process begins just like any other project, with baby steps. First it is needed to build a parser for the syntax(parser.c). We will discuss the initial syntax in the next section. After which we must build our semantics analyzer which will build and test the abstract syntax tree (AST). Then we will need to build the code generator and linker. 

### The Syntax

The Sytax is very simple to start with, for initial development purposes we are going to use two basic libraries:
  1. I/O
    - out: out \<var\> | \<val\>;
    - in: in \<var\> | \<var\> \<val\>;
  2. Math
    - add: add \<val\>* | \<var\>*;
    - sub: sub \<val\>* | \<var\>*;
    - mul: mul \<val\>* | \<var\>*;
    - devide: devide \<val\>* | \<var\>*;

### The Task Lists

  1. Complete the parsers tokenizer 
  2. Build the Semantics Anaylyzer
  3. Build the Code Generator
  4. Build the Linker. 
