/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/3/6 12:26:08 by pshandy           #+#    #+#               */
/*   Updated: 2022/3/6 12:26:10 by pshandy          ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance_to_tag(int tag, int size)
{
	if (tag >= size / 2)
		tag -= size;
	return (tag);
}

int	distance_to_top(t_stack *a, int idx)
{
	int	i;
	int	size;

	i = 0;
	size = get_stack_size(a);
	while (a)
	{
		if (a->index == idx)
			break ;
		a = a->next;
		i++;
	}
	if (i > size / 2)
		i -= size;
	return (i);
}

t_stack	*get_closest_to_top(t_stack *stack, int size)
{
	t_stack	*tmp;
	t_stack	*closest;
	int		distance;
	int		cur_dist;

	distance = ~0U >> 1;
	closest = NULL;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index <= size && !tmp->keep)
		{
			cur_dist = distance_to_top(stack, tmp->index);
			if (ft_abs(cur_dist) < ft_abs(distance))
			{
				distance = cur_dist;
				closest = tmp;
				if (distance == 0)
					break ;
			}
		}
		tmp = tmp->next;
	}
	return (closest);
}
