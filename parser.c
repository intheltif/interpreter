/*
 * parser.c - recursive descent parser for a simple expression language.
 *            Most of the functions in this file model a Non-terminal in the
 *            grammar listed below
 * Author: William Kreahling and Mark Holliday
 * Date:   Modified 9-29-08 and 3-25-15
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "tokenizer.h"
#include "parser.h"

/*
 * <bexpr> ::= <expr> ;
 * <expr> ::=  <term> <ttail>
 * <ttail> ::=  <add_sub_tok> <term> <ttail> | e
 * <term> ::=  <stmt> <stail>
 * <stail> ::=  <mult_div_tok> <stmt> <stail> | e
 * <stmt> ::=  <factor> <ftail>
 * <ftail> ::=  <compare_tok> <factor> <ftail> | e
 * <factor> ::=  <expp> ^ <factor> | <expp>
 * <expp> ::=  ( <expr> ) | <num>
 * <add_sub_tok> ::=  + | -
 * <mul_div_tok> ::=  * | /
 * <compare_tok> ::=  < | > | <= | >= | ! = | ==
 * <num> ::=  {0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9}+
 */


// <expr> -> <term> <ttail>
int expr(char *token)
{
   int subtotal = term(token);
   if (subtotal == ERROR)
      return subtotal;
   else
      return ttail(token, subtotal);
}

//<ttail> -> <add_sub_tok> <term> <ttail> | e
int ttail(char *token, int subtotal)
{
   int term_value;

   if (!strncmp(token, "+", 1))
   {
      add_sub_tok(token);
      term_value = term(token);

      // if term returned an error, give up otherwise call ttail
      if (term_value == ERROR)
         return term_value;
      else
         return ttail(token, (subtotal + term_value));
   }
   else if(!strncmp(token, "-", 1))
   {
      add_sub_tok(token);
      term_value = term(token);

      // if term returned an error, give up otherwise call ttail
      if (term_value == ERROR)
         return term_value;
      else
         return ttail(token, (subtotal - term_value));
   }
   /* empty string */
   else
      return subtotal;
}

/**
 * <bexpr> -> 
 *
 */
int bexpr(char *token) {

    //TODO finish function

} // end bexpr()

/**
 * <term> -> 
 *
 */
int term(char *token) {

    //finish function

} // end term()

/**
 * <stmt> -> 
 *
 */
int stmt(char *token) {

    //TODO finish function

} //end stmt()

/**
 * <stail> ->
 *
 */
int stail(char *token, int subtotal) {

    //TODO finish function

} //ends stail()

/**
 * <stail> ->
 *
 */
int factor(char *token) {

    //TODO finish function

} //end factor()
int ftail(char *token, int subtotal) {

    //TODO finish function

} //end ftail()

/**
 * <expp> -> 
 *
 */
int expp(char *token) {

    //TODO finish function

} //end expp()

/**
 *
 */
void add_sub_tok(char *token) {

    //TODO finish function

} //end add_sub_tok()

/**
 *
 */
void mul_div_tok(char *token) {

    //TODO finish function

} //end mul_div_tok()

/**
 *
 */
void compare_tok(char *token) {

    //TODO finish function

} //end compare_tok()

/**
 * helper function
 *
 */
void expon_tok(char *token) {

    //TODO finish function

} //end expon_tok()

/**
 *
 */
int num(char *token) {

    //TODO finish function

} //end num

/**
 * helper function
 *
 */
int is_number(char *token) {

    //TODO finish function

} //end is_number()
