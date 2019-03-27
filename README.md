Author: Carlee Yancey
Author: Evert Ball
Version: April 10, 2019

# Project 3: An Interpreter for Arithmetic Expressions that usa a Recursive 
# Descent Parser

##Description
This project in an interpreter in C for arithmetic expressions ad defined by a 
particular grammer that is implemented using a recursive descent parser. This 
program takes in an input file and check to see if there are any lexical errors,
if not, then checks for it the input is syntactically correct. Then outputs to 
a file.

##Files Used:
input\_left\_associative.txt
output.txt
tokenizer.c
tokenizer.h
parser.c
parser.h
interpreter.c

## Usage
### To Complie:
    gcc -Wall interpreter.c -o interpreter

### To Run:
    ./interpreter ./input_and_output_files/input_left_associative.txt output.txt

## Output
### If there are no errors found.(Normal output)
    
    <the input line>
    Syntax OK
    Value is <subtotal>

### If there is an lexical Error found.
    
    <the input line>
    ===> '<token>'
    Lexical Error: not a lexeme

### If there is a Syntax Error.
    
    <the input line>    
    ===> '<token>' expected
    Syntax Error

## Bugs 
Currently there are no bug is out program.
