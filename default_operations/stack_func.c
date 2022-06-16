/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/3/6 12:26:08 by pshandy           #+#    #+#               */
/*   Updated: 2022/3/6 12:26:10 by pshandy          ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_element(int data)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (elem == NULL)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void	push(t_stack **stack, int data)
{
	t_stack	*new;

	new = create_element(data);
	if (*stack)
	{
		new->next = *stack;
		*stack = new;
	}
	else
		*stack = new;
}

int	pop(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL)
		return (-1);
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	tmp = NULL;
	return (1);
}

void	clear(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*l;

	l = *head;
	while (l)
	{
		if (l->next)
			tmp = l->next;
		else
			tmp = NULL;
		free(l);
		l = tmp;
	}
	*head = NULL;
}
