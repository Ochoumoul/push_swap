/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:24:10 by ochoumou          #+#    #+#             */
/*   Updated: 2022/04/07 00:58:00 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct node {
	int			value;
	int			index;
	int			sub_index;
	int			length;
	int			flag;
	struct node	*next;
}	t_node;

typedef t_node	*t_stack;

char	*ft_strdup(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
char	**ft_split(char *s, char c);
char	**parse_input(int argc, char **args, int *elements);
char	*get_next_line(int fd);
t_node	*pop_el(t_stack *stack);
t_node	*min_number(t_stack *stack);
t_node	*max_length(t_stack *stack);
t_node	*best_element(t_stack *stack);
t_node	*find_index(t_stack *stack, int index);
void	sort_all(t_stack *stackA, t_stack *stackB);
void	smart_top(t_stack *stackA, t_stack *stackB, \
t_node *nodeA, t_node *nodeB);
void	smart_rr(t_stack *stackA, t_stack *stackB, \
t_node *nodeA, t_node *nodeB);
void	free_table(char **table);
void	validation_error(int code, char **numbers);
void	clear_stack(t_stack *stack);
void	pair(t_stack *stack, t_node *node);
void	ft_error(void);
void	flag_best_element(t_stack *stackA, t_stack *stackB);
void	top_min_element(t_stack *stackA);
void	find_list(t_stack *stack);
void	index_stack(t_stack *stack);
void	sort_three(t_stack *stack_a);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort_all(t_stack *stackA, t_stack *stackB);
void	swap_el(t_stack *stack, char *inst);
void	print_instruction(char *str);
void	swap_both(t_stack *stackA, t_stack *stackB, char *inst);
void	rotate_both(t_stack *stackA, t_stack *stackB, char *inst);
void	reverse_rotate_both(t_stack *stackA, t_stack *stackB, char *inst);
void	search_best_element(t_stack *stackA, t_stack *stackB);
void	sort_stack(t_stack *stackA, t_stack *stackB);
void	clear_stack(t_stack *stack);
void	stack_error(t_stack *stack);
void	print_stack(t_stack *stack);
void	pair_elements(t_stack *stackA, t_stack *stackB);
void	rotate_el(t_stack *stack, char *inst);
void	reverse_rotate_el(t_stack *stack, char *inst);
void	insert_numbers(t_stack *stack, char **argv, int argc);
int		check_sorted_stack(t_stack *stack);
int		check_sorted_stack(t_stack *stack);
int		push_el(t_stack *stack, int value);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
long	ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int		find_el(t_stack *stack, int value);
int		stack_size(t_stack *stack);
int		max(int value1, int value2);
int		flag_elements(t_stack *stack);
int		calculate_instruction(t_node *node, int size, int *desicion);
int		push_stack(t_stack *stackA, t_stack *stackB, char *inst);
int		max(int value1, int value2);
int		find_el(t_stack *stack, int value);
int		count_elements(char **table);
int		validate_number(char *str);
int		count_elements(char **table);

#endif