/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                    :+:      :+:    :+:   */
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

int	get_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack	*get_min_elem(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = head;
	min = head;
	while (tmp)
	{
		if (tmp->data < min->data)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*get_max_elem(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = head;
	max = head;
	while (tmp)
	{
		if (tmp->data > max->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*get_last_elem(t_stack *l)
{
	if (l == NULL)
		return (NULL);
	while (l->next)
	{
		l = l->next;
	}
	return (l);
}
