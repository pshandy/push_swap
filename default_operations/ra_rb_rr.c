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

static void	_rotate(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	*head = (*head)->next;
	tmp->next->next = NULL;
}

void	ra(t_stack **a, int flag)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	_rotate(a);
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int flag)
{
	if (*b == NULL || (*b)->next == NULL)
		return ;
	_rotate(b);
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int flag)
{
	if (!(*a == NULL || (*a)->next == NULL))
		_rotate(a);
	if (!(*b == NULL || (*b)->next == NULL))
		_rotate(b);
	if (flag == 1)
		write(1, "rr\n", 3);
}
