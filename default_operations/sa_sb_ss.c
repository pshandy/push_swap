/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/3/6 12:26:08 by pshandy           #+#    #+#               */
/*   Updated: 2022/3/6 12:26:10 by pshandy          ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_higher(t_stack **head)
{
	t_stack	*tmp;

	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

void	sa(t_stack **a, int flag)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	swap_higher(a);
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int flag)
{
	if (*b == NULL || (*b)->next == NULL)
		return ;
	swap_higher(b);
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int flag)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	swap_higher(a);
	swap_higher(b);
	if (flag == 1)
		write(1, "ss\n", 3);
}
