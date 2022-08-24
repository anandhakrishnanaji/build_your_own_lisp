#include<stdio.h>
#include<stdlib.h>

#include<editline/readline.h>

#include "mpc.h"

int main(int argc,char** argv){

  mpc_parser_t* Number   = mpc_new("number");
  mpc_parser_t* Operator = mpc_new("operator");
  mpc_parser_t* Expr     = mpc_new("expr");
  mpc_parser_t* Spython    = mpc_new("spython");

  mpca_lang(MPCA_LANG_DEFAULT,
  "                                                     \
    number   : /-?[0-9]+/ ;                             \
    operator : '+' | '-' | '*' | '/' ;                  \
    expr     : <number> | '(' <operator> <expr>+ ')' ;  \
    lispy    : /^/ <operator> <expr>+ /$/ ;             \
  ",
  Number, Operator, Expr, Spython);


  puts("Spython version 0.0.0.0.1");
  puts("Press Ctrl+c to Exit\n");
  while(1){
    char *input=readline("spython> ");

    add_history(input);

    printf("No you're a %s\n",input);

    free(input);

  }
  mpc_cleanup(4,Number,Operator,Expr,Spython);
  return 0;
}
