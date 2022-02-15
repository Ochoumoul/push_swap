#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define STACK_EMPTY INT_MIN

typedef struct node 
{	
	int value;
	struct node *next;
} node;

typedef node *stack;

bool push(stack *stack,int value)
{
	node *newnode = malloc(sizeof(node));
	if (newnode == NULL) return (false);
	printf("%p\n", *stack);
	newnode->value = value;
	newnode->next = *stack;
	*stack = newnode;
	return (true);
}

int pop(stack *stack)
{
	if (*stack == NULL) return STACK_EMPTY;
	int result = (*stack)->value;
	
	node *tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	return (result);
}

int	main()
{
	stack a = NULL;
	stack b = NULL;
	push(&a,53);
	push(&a,82);
	push(&a,12);
	push(&b,63);
	push(&b,812);
	push(&b,2);
	int t;
	while (((t = pop(&b)) != STACK_EMPTY))
	{
		printf("t = %d\n", t);
	}
	return (0);
}
