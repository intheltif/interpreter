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


/**
 * This function parses the grammer for <term> as defined below.
 *      
 *      Grammer:
 *          <expr> -> <term> <ttail>
 *
 * @param token the token to parse.
 * @return a few different things could be returned <-- TODO fix this desc.
 */
int expr(char *token)
{
   printf("\nEntered <expr>\n");
   int subtotal = term(token);
   if (subtotal == ERROR) {
      return subtotal;
   } else {
      printf("\nExited <expr>\n");
      return ttail(token, subtotal);
   }
}

/**
 * This function parses the grammer for <term> as defined below.
 *      
 *      Grammer:
 *          <ttail> -> <add_sub_tok> <term> <ttail> | e
 *
 * @param token the token to parse.
 * @param subtotal The current subtotal.
 * @return a few different things could be returned <-- TODO fix this desc.
 */
int ttail(char *token, int subtotal)
{

   printf("\nEntered <ttail>\n");
   int term_value;

   if (!strncmp(token, "+", 1))
   {
      add_sub_tok(token);
      term_value = term(token);

      // if term returned an error, give up otherwise call ttail
      if (term_value == ERROR) {
          printf("\nExited <ttail>\n");
          return term_value;
      } else {
          return ttail(token, (subtotal + term_value));
      }
   }
   else if(!strncmp(token, "-", 1))
   {
      add_sub_tok(token);
      term_value = term(token);

      // if term returned an error, give up otherwise call ttail
      if (term_value == ERROR) {
         printf("\nExited <ttail>\n");
         return term_value;
      }
      else
         return ttail(token, (subtotal - term_value));
   }
   /* empty string */
   else 
   {
      printf("\nExited <ttail>\n");
      return subtotal;
   }
}

/**
 * This function parses the grammer for <term> as defined below.
 *
 *      Grammer:
 *          <bexpr> -> <expr>
 *
 * @param token the token to parse.
 * @return a few different things could be returned <-- TODO fix this desc.
 */
int bexpr(char *token) {

    printf("\nEntered <bexpr>\n");

    int subtotal = 0;
    
    subtotal = expr(token);
    printf("\nExited <bexpr>\n");
    return subtotal;

} // end bexpr()

/**
 * This function parses the grammer for <term> as defined below.
 *      
 *      Grammer:
 *          <term> -> <stmt> <stail>
 *
 * @param token the token to parse.
 * @return a few different things could be returned <-- TODO fix this desc.
 */
int term(char *token) {

    printf("\nEntered <term>\n");

    int subtotal = stmt(token);

    if(subtotal == ERROR) {
        printf("\nExited <term>\n");
        return subtotal;
    } else {
        printf("\nExited <term>\n");
        return stail(token, subtotal);
    }

} // end term()

/**
 * This function parses the grammer for <stmt> as defined below.
 *
 *      Grammer:
 *          <stmt> -> <factor> <ftail>
 *
 * @param token the token to parse.
 * @return a few different things could be returned <-- TODO fix this desc.
 */
int stmt(char *token) {
    //TODO remove first '\n' from printf?
    printf("\nEntered <stmt>\n");

    int subtotal = factor(token);

    if(subtotal == ERROR) {
        printf("\nExited <stmt>\n");
        return subtotal;
    } else {
        printf("\nExited <stmt>\n");
        return ftail(token, subtotal);
    }

} //end stmt()

/**
 * This function parses the grammer for <stail> as defined below.
 *
 *      Grammer:
 *          <stail> -> <mult_div_tok> <stmt> <stail> | e
 *
 * @param token the token to parse.
 * @param subtotal The current subtotal.
 * @return a few different things could be returned <-- TODO fix this desc.
 */
int stail(char *token, int subtotal) {

    //TODO finish function
    int stmt_value;

    if( !strncmp(token, "*", 1) ) {
        
        mult_div_tok(token);
        stmt_value = stmt(token);
        
        // If stmt returned an error, give up. Otherwise, call stail.
        if(stmt_value == ERROR) {
            printf("\nExited <stail>\n");
            return stmt_value;
        } else {
            return stail( token, (subtotal * stmt_value) );
        }
    } else if( !strncmp(token, "/", 1) ) {
        
        mult_div_tok(token);
        stmt_value = stmt(token);
        
        // If stmt returned an error, give up. Otherwise, call stail.
        if(stmt_value == ERROR) {
            printf("\nExited <stail>\n");
            return stmt_value;
        } else {
            return stail( token, (subtotal / stmt_value) );
        }
    /* empty string */
    } else { 
        printf("\nExited <stail>\n");
        return subtotal;
    }

} //ends stail()

/**
 * This function parses the grammer for <factor> as defined below.
 *      
 *      Grammer:
 *          <factor> -> <expp> ^ <factor> | <expp>
 *
 * @param token the token to parse.
 * @return a few different things could be returned <-- TODO fix this desc.
 */
int factor(char *token) {

    //TODO finish function

    if() {

    } else if() {

    } else {
        printf("\nExited <factor>\n");
        return expp(token);
    }

} //end factor()

/**
 * This function takes care of the grammer for <ftail> as defined below.
 *      
 *      Grammer:
 *          <ftail> -> <compare_tok> <factor> <ftail> | e
 *
 * @param token the token to parse.
 * @param subtotal The current subtotal.
 * @return a few different things could be returned <-- TODO fix this desc.
 */
int ftail(char *token, int subtotal) {

    printf("\nEntered <ftail>\n");

    //TODO finish function
    if() {

    } else if() {

    } else {
        printf("\nExited <ftail>\n");
        return subtotal
    }

} //end ftail()

/**
 * This function takes care of the grammer for <expp> as defined below.
 *
 *      Grammer:
 *          <expp> -> ( <expr> ) | <num>
 *
 * @param token the token to parse
 * @return a few different things could be returned <-- TODO fix this desc.
 */
int expp(char *token) {
    
    int subtotal;

    /* If there is an open parenthesis, start that part of the grammer */
    if(!strncmp(token, "(", 1)) {

        get_token(token); //get's the "(" and moves to <expr>
        subtotal = expr(token);

        /* gets the ")" and returns the subtotal. */
        if(!strncmp(token, ")", 1)) {
            get_token(token); 
            return subtotal;
        /* otherwise there was an error */
        } else {
            //do error
        }
    /* no parenthesis, must be a number */
    } else {
        return num(token);
    }

} //end expp()

/**
 * Grammer:
 *      <add_sub_tok> -> + | -
 */
void add_sub_tok(char *token) {

    //TODO finish function
    
    if() {
        //do +
    } else {
        //do -
    }

} //end add_sub_tok()

/**
 * Grammer:
 *      <mul_div_tok> ->  * | /
 *
 */
void mul_div_tok(char *token) {

    //TODO finish function

    if() {
        //do *
    } else {
        //do /
    }

} //end mul_div_tok()

/**
 * Grammer:
 *      <compare_tok> ->  < | > | <= | >= | ! = | ==
 *
 */
void compare_tok(char *token) {

    //TODO finish function
    
    switch(token) {
        case "<":
            //do <
            break;
        case ">":
            //do >
            break;
        

} //end compare_tok()

/**
 * helper function
 *
 */
void expon_tok(char *token) {

    //TODO finish function

} //end expon_tok()

/**
 * Grammer:
 *      <num> ->  {0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9}+
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
