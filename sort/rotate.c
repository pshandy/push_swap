/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/3/6 12:26:08 by pshandy           #+#    #+#               */
/*   Updated: 2022/3/6 12:26:10 by pshandy          ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	d_rotate(t_stack **stack_a, t_stack **stack_b, int *rot_a, int *rot_b)
{
	while (*rot_a > 0 && *rot_b > 0)
	{
		(*rot_a)--;
		(*rot_b)--;
		rr(stack_a, stack_b, 1);
	}
	while (*rot_a < 0 && *rot_b < 0)
	{
		(*rot_a)++;
		(*rot_b)++;
		rrr(stack_a, stack_b, 1);
	}
}

void	rotate(t_stack **stack_a, t_stack **stack_b, int rot_a, int rot_b)
{
	d_rotate(stack_a, stack_b, &rot_a, &rot_b);
	while (rot_a > 0)
	{
		rot_a--;
		ra(stack_a, 1);
	}
	while (rot_a < 0)
	{
		rot_a++;
		rra(stack_a, 1);
	}
	while (rot_b > 0)
	{
		rot_b--;
		rb(stack_b, 1);
	}
	while (rot_b < 0)
	{
		rot_b++;
		rrb(stack_b, 1);
	}
}
