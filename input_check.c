/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/3/6 12:26:08 by pshandy           #+#    #+#               */
/*   Updated: 2022/3/6 12:26:10 by pshandy          ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	is_numeric(char *str)
{
	if (*str && *str == '0' && *(str + 1) != '\0')
		return (0);
	if (*str)
	{
		while (*str)
		{
			if (!(*str >= '0' && *str <= '9'))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}

int	is_int(char *str)
{
	char	*comp;
	size_t	i;

	i = 0;
	if (str[0] == '-')
		if (str[++i] == '0')
			return (0);
	comp = ft_itoa((~0U >> 1) + i);
	if (ft_strlen(str) > ft_strlen(comp) || !is_numeric(&str[i]))
		return (0);
	if (ft_strlen(str) < ft_strlen(comp))
	{
		free(comp);
		return (1);
	}
	while (i < ft_strlen(str))
	{
		if (!(str[i] <= comp[i]))
			return (0);
		if (str[i] < comp[i])
			return (1);
		i++;
	}
	free(comp);
	return (1);
}

int	check(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
		return (0);
	i = 1;
	while (argv[i])
	{
		j = 1;
		if (!is_int(argv[i]))
			return (0);
		while (j != i)
		{
			if (ft_strcmp(argv[j], argv[i]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
