/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/3/6 12:26:08 by pshandy           #+#    #+#               */
/*   Updated: 2022/03/07 11:30:47 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int			size_a;
	int			markup;

	if (is_sorted(stack_a))
		return ;
	if (argc <= 4)
		sort_three(stack_a);
	else if (argc <= 6)
		sort_five(stack_a, stack_b);
	else
	{
		index_all(stack_a);
		size_a = get_stack_size(*stack_a);
		markup = best_markup(*stack_a, 1);
		sort_other(stack_a, stack_b, size_a, markup);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (!check(argc, argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	i = argc - 1;
	while (i > 0)
	{
		push(&stack_a, ft_atoi(argv[i]));
		i--;
	}
	solve(&stack_a, &stack_b, argc);
	clear(&stack_a);
	clear(&stack_b);
}
