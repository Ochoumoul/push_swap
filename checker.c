#include "push_swap.h"
#include <string.h>

void    apply_single(char *inst, t_stack *stackA, t_stack *stackB)
{
    if (strcmp(inst, "pa") == 0)
        push_stack(stackB, stackA, "");
    else if (strcmp(inst, "pb") == 0)
        push_stack(stackA, stackB, "");
    else if (strcmp(inst, "ra") == 0)
        rotate_el(stackA, "");
    else if (strcmp(inst, "rb") == 0)
        rotate_el(stackB, "");
    else if (strcmp(inst, "sa") == 0)
        swap_el(stackB, "");
    else if (strcmp(inst, "sb") == 0)
        swap_el(stackB, "");
}

void    apply_double(char *inst, t_stack *stackA, t_stack *stackB);

int main(int argc,char **argv)
{
    int el;
    char *str;

    el = 0;
    if (argc > 1)
    {
        argv = validate_args(argc, argv, &el);
        el -= 1; // We subtracted one for the array index.
        while ((str = get_next_line(0)) != NULL)
        {
            printf("%s", str);
        }
    }
    else
        printf("Invalid number of agruments\n");
    return (0);
}