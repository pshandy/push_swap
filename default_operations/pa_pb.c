/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/3/6 12:26:08 by pshandy           #+#    #+#               */
/*   Updated: 2022/3/6 12:26:10 by pshandy          ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}

void	pa(t_stack **a, t_stack **b, int flag)
{
	if (*b == NULL)
		return ;
	move(b, a);
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int flag)
{
	if (*a == NULL)
		return ;
	move(a, b);
	if (flag == 1)
		write(1, "pb\n", 3);
}
