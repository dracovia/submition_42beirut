/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:50:43 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/31 15:46:24 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicate(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	count_numbers(int ac, char **av)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((j == 0 || av[i][j - 1] == ' ') && av[i][j] != ' ')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	parse_args_to_stack(int ac, char **av, t_stack *a)
{
	int		*tmp;
	int		count;
	int		total;

	total = count_numbers(ac, av);
	tmp = malloc(sizeof(int) * total);
	if (!tmp)
		return (0);
	count = fill_stack_from_args(ac, av, a, tmp);
	if (!count || has_duplicate(tmp, total))
		return (free(tmp), 0);
	free(tmp);
	return (1);
}

static int	fill_stack_from_args(int ac, char **av, t_stack *a, int *tmp)
{
	int		i;
	int		j;
	int		val;
	int		ok;
	int		count;
	char	**split;

	count = 0;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			ok = 1;
			val = ps_atoi(split[j], &ok);
			if (!ok)
				return (ft_free_split(split), 0);
			tmp[count++] = val;
			push_back(a, val);
			j++;
		}
		ft_free_split(split);
		i++;
	}
	return (count);
}
