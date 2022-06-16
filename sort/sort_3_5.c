/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/3/6 12:26:08 by pshandy           #+#    #+#               */
/*   Updated: 2022/3/6 12:26:10 by pshandy          ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	max;
	int	size;

	size = get_stack_size(*a);
	max = get_max_elem(*a)->data;
	if (size == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a, 1);
		return ;
	}
	else if (size == 3)
	{
		if ((*a)->data == max)
			ra(a, 1);
		if ((*a)->next->data == max)
			rra(a, 1);
		if ((*a)->data > (*a)->next->data)
			sa(a, 1);
	}
}

void	sort_five(t_stack **stack, t_stack **b)
{
	int	min;
	int	max;

	min = get_min_elem(*stack)->data;
	max = get_max_elem(*stack)->data;
	while (get_stack_size(*b) < 2)
	{
		if ((*stack)->data == min || (*stack)->data == max)
			pb(stack, b, 1);
		else
			ra(stack, 1);
	}
	sort_three(stack);
	pa(stack, b, 1);
	pa(stack, b, 1);
	if ((*stack)->data == get_max_elem(*stack)->data)
		ra(stack, 1);
	else
	{
		sa(stack, 1);
		ra(stack, 1);
	}
}
