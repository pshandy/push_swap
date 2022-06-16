/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/3/6 12:26:08 by pshandy           #+#    #+#               */
/*   Updated: 2022/3/6 12:26:10 by pshandy          ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				data;
	int				keep;
	int				index;
	struct s_stack	*next;
}				t_stack;

typedef struct s_struct
{
	int		max_dist;
	int		dist_total;
	int		insert;
	int		distance_b;
}				t_struct;

int		pop(t_stack **stack);
int		ft_abs(int a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_strcmp(char *s1, char *s2);
int		is_numeric(char *str);
int		is_int(char *str);
int		ft_strcmp(char *s1, char *s2);
int		check(int argc, char **argv);
int		markup(t_stack *stack, t_stack *start, int set);
int		best_markup(t_stack *start, int set);
int		is_sorted(t_stack **head);
int		distance_to_top(t_stack *a, int idx);
int		distance_to_tag(int tag, int size);
int		get_stack_size(t_stack *stack);
int		can_swap(t_stack *list);
void	ra(t_stack **a, int flag);
void	rb(t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b, int flag);
void	rra(t_stack **a, int flag);
void	rrb(t_stack **b, int flag);
void	rrr(t_stack **a, t_stack **b, int flag);
void	sa(t_stack **a, int flag);
void	sb(t_stack **b, int flag);
void	ss(t_stack **a, t_stack **b, int flag);
void	pa(t_stack **a, t_stack **b, int flag);
void	pb(t_stack **a, t_stack **b, int flag);
void	d_rotate(t_stack **stack_a, t_stack **stack_b, int *rot_a, int *rot_b);
void	rotate(t_stack **stack_a, t_stack **stack_b, int rot_a, int rot_b);
void	sort_three(t_stack **a);
void	sort_five(t_stack **stack, t_stack **b);
void	push(t_stack **stack, int data);
void	clear(t_stack **head);
void	index_all(t_stack **head);
void	sort_other(t_stack **a, t_stack **b, int size_a, int markup);
t_stack	*create_element(int data);
t_stack	*get_min_elem(t_stack *head);
t_stack	*get_max_elem(t_stack *head);
t_stack	*get_last_elem(t_stack *l);
t_stack	*get_greater_elem(t_stack *head, t_stack *comp);
t_stack	*get_closest_to_top(t_stack *stack, int size);

#endif
