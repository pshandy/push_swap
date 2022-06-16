/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheecker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/3/6 12:26:08 by pshandy           #+#    #+#               */
/*   Updated: 2022/3/6 12:26:10 by pshandy          ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (*head == NULL)
		return (1);
	tmp = *head;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
		if (tmp->data < prev->data)
			return (0);
	}
	return (1);
}

static int	perform_action(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(str, "sa"))
		sa(a, 0);
	else if (!ft_strcmp(str, "sb"))
		sb(b, 0);
	else if (!ft_strcmp(str, "ss"))
		ss(a, b, 0);
	else if (!ft_strcmp(str, "pa"))
		pa(a, b, 0);
	else if (!ft_strcmp(str, "pb"))
		pb(a, b, 0);
	else if (!ft_strcmp(str, "ra"))
		ra(a, 0);
	else if (!ft_strcmp(str, "rb"))
		rb(b, 0);
	else if (!ft_strcmp(str, "rr"))
		rr(a, b, 0);
	else if (!ft_strcmp(str, "rra"))
		rra(a, 0);
	else if (!ft_strcmp(str, "rrb"))
		rrb(b, 0);
	else if (!ft_strcmp(str, "rrr"))
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

static int	process_read(t_stack **stack_a, t_stack **stack_b)
{
	char	str[4];
	int		index;
	int		prev_index;

	index = 0;
	while (index < 4)
	{
		prev_index = index;
		index += read(0, str + index, 1);
		if (prev_index == index)
			break ;
		if (str[prev_index] == '\n')
		{
			str[prev_index] = 0;
			if (!perform_action(str, stack_a, stack_b))
				return (0);
			index = 0;
		}
	}
	if (index == 4)
		return (0);
	return (1);
}

static void	solve_checker(t_stack **stack_a, t_stack **stack_b)
{
	if (process_read(stack_a, stack_b))
	{
		if (is_sorted(stack_a))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	else
		ft_putstr_fd("Error\n", 1);
	clear(stack_a);
	clear(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (!check(argc, argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	i = argc - 1;
	while (i > 0)
	{
		push(&stack_a, ft_atoi(argv[i]));
		i--;
	}
	solve_checker(&stack_a, &stack_b);
}
