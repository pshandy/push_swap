/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/3/6 12:26:08 by pshandy           #+#    #+#               */
/*   Updated: 2022/3/6 12:26:10 by pshandy          ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	markup(t_stack *stack, t_stack *start, int set)
{
	t_stack	*tmp;
	int		max_idx;
	int		count;

	max_idx = -1;
	count = 0;
	tmp = start;
	while (tmp)
	{
		if (set)
			tmp->keep = 0;
		if (tmp->index > max_idx)
		{
			max_idx = tmp->index;
			count++;
			if (set)
				tmp->keep = 1;
		}
		tmp = tmp->next;
		if (tmp == NULL)
			tmp = stack;
		if (tmp == start)
			break ;
	}
	return (count);
}

int	best_markup(t_stack *start, int set)
{
	t_stack		*tmp;
	t_stack		*max_keep;
	int			max;
	int			count;

	max = 0;
	tmp = start;
	while (tmp)
	{
		count = markup(start, tmp, 0);
		if (count > max)
		{
			max = count;
			max_keep = tmp;
		}
		tmp = tmp->next;
	}
	if (set)
		markup(start, max_keep, 1);
	return (max);
}

int	can_swap(t_stack *list)
{
	t_stack	fake;
	t_stack	fake2;
	int		count;
	int		count2;

	fake.next = &fake2;
	fake.index = list->next->index;
	fake2.next = list->next->next;
	fake2.index = list->index;
	count = best_markup(list, 0);
	count2 = best_markup(&fake, 0);
	if (count2 > count)
		return (1);
	return (0);
}
