/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/3/6 12:26:08 by pshandy           #+#    #+#               */
/*   Updated: 2022/3/6 12:26:10 by pshandy          ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_greater_elem(t_stack *head, t_stack *comp)
{
	t_stack	*tmp;
	t_stack	*greater;

	tmp = head;
	greater = get_max_elem(head);
	while (tmp)
	{
		if (tmp->data < greater->data && tmp->data > comp->data)
			greater = tmp;
		tmp = tmp->next;
	}
	if (greater == comp)
		return (NULL);
	return (greater);
}

void	index_all(t_stack **head)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = get_min_elem(*head);
	while (tmp)
	{
		tmp->index = i++;
		tmp = get_greater_elem(*head, tmp);
	}
}
