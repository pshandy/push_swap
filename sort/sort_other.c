/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/3/6 12:26:08 by pshandy           #+#    #+#               */
/*   Updated: 2022/3/6 12:26:10 by pshandy          ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insert_distance(t_stack *list, int t, int size)
{
	t_stack	*p;
	t_stack	*c;
	int		c_max[2];
	int		i;

	i = 0;
	p = get_last_elem(list);
	c = list;
	c_max[1] = ~0U >> 1;
	while (c)
	{
		if ((p->index > c->index && (t < c->index || t > p->index))
			|| (t > p->index && t < c->index))
		{
			c_max[0] = i;
			if (c_max[0] > size / 2)
				c_max[0] -= size;
			if (ft_abs(c_max[0]) < c_max[1])
				c_max[1] = c_max[0];
		}
		p = c;
		c = c->next;
		i++;
	}
	return (c_max[1]);
}

void	calculate_b_rotation(t_stack **a, t_stack **b, int *rot_a, int *rot_b)
{
	t_stack		*tmp;
	t_struct	s;
	int			i;

	s.max_dist = ~0U >> 1;
	i = 0;
	tmp = *b;
	while (tmp)
	{
		s.distance_b = distance_to_tag(i++, get_stack_size(*b));
		s.insert = insert_distance(*a, tmp->index, get_stack_size(*a));
		s.dist_total = ft_abs(s.insert) + ft_abs(s.distance_b);
		if (s.insert > 0 && s.distance_b > 0)
			s.dist_total -= ft_min(s.distance_b, s.insert);
		if (s.insert < 0 && s.distance_b < 0)
			s.dist_total += ft_max(s.distance_b, s.insert);
		if (s.dist_total < s.max_dist)
		{
			s.max_dist = s.dist_total;
			*rot_a = s.insert;
			*rot_b = s.distance_b;
		}
		tmp = tmp->next;
	}
}

void	populate_b(t_stack **stack_a, t_stack **stack_b, int *size_a)
{
	int	rot_a;
	int	rot_b;

	while (*stack_b)
	{
		calculate_b_rotation(stack_a, stack_b, &rot_a, &rot_b);
		rotate(stack_a, stack_b, rot_a, rot_b);
		pa(stack_a, stack_b, 1);
		*size_a = *size_a + 1;
	}
	rotate(stack_a, stack_b, distance_to_top(*stack_a, 0), 0);
}

void	sort_other(t_stack **a, t_stack **b, int size_a, int markup)
{
	int		distance;
	t_stack	*tmp;

	while (size_a >= markup)
	{
		tmp = get_closest_to_top(*a, get_stack_size(*a) + get_stack_size(*b));
		if (tmp == NULL)
			break ;
		distance = distance_to_top(*a, tmp->index);
		if (*a && can_swap(*a))
		{
			sa(a, 1);
			markup = best_markup(*a, 1);
		}
		else if (*a != NULL && (*a)->keep == 0 && distance == 0)
		{
			pb(a, b, 1);
			size_a--;
		}
		else
			rr(a, b, 1);
	}
	populate_b(a, b, &size_a);
}
