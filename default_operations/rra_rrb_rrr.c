/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/3/6 12:26:08 by pshandy           #+#    #+#               */
/*   Updated: 2022/3/6 12:26:10 by pshandy          ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_rev(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *head;
	*head = tmp->next;
	tmp->next = NULL;
}

void	rra(t_stack **a, int flag)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	rotate_rev(a);
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int flag)
{
	if (*b == NULL || (*b)->next == NULL)
		return ;
	rotate_rev(b);
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	if (!(*a == NULL || (*a)->next == NULL))
		rotate_rev(a);
	if (!(*b == NULL || (*b)->next == NULL))
		rotate_rev(b);
	if (flag == 1)
		write(1, "rrr\n", 4);
}
