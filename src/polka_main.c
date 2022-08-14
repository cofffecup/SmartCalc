#include "calc.h"

double from_infix_to_postfix(char *exp, double x_value) {
    queue *exp_q = create_queue(exp, x_value);
    queue *postfix = make_posfix_queue(exp_q);
    double res = calculation_process(postfix);
    destroy(exp_q);
    destroy(postfix);
    return res;
}

void destroy(queue *root) {
    while (root) {
        root = root->next;
        free(root);
    }
}
