#ifndef CALC_H
#define CALC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define CORRECT 1
#define INCORRECT 0

typedef struct queue {
    double volume;
    char op[2];
    float priority;
    struct queue *next;
} queue;


double check();

double from_infix_to_postfix(char *exp, double x_value);

queue *create_node();
queue *create_queue(char *exp, double x_value);
int is_num_char(char c);
int is_op_char(char exp);
int is_space(char c);
double get_num_from_string(char **exp);
void destroy(queue *root);
int priority_parser(char operation);
int is_un_min(const char *p, const char *head);
void function_parser(char **exp, queue **process);


queue *make_posfix_queue(queue *exp);

queue *create_stack_node();
void stack_push(queue **stack, queue *exp);
void stack_pop(queue **stack, queue **process, int priority);
void stack_remove(queue **stack, int count);
void create_process_node(queue **process);

double calculation_process(queue *exp);

void stack_calc_pop(queue **stack, char *op);
void stack_calc_push(queue **stack, double num);
double calc_parser(double first, double second, char *op);

#endif // CALC_H
