/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 22:11:34 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/17 22:11:34 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

// ---------- helpers ----------

// simple atoi with overflow check
static int	ps_atoi(const char *s, int *ok)
{
	long	num = 0;
	int		sign = 1;

	if (*s == '+' || *s == '-')
		if (*s++ == '-') sign = -1;
	if (!*s) return (*ok = 0, 0);
	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			return (*ok = 0, 0);
		s++;
	}
	if (*s != '\0')
		return (*ok = 0, 0);
	return ((int)(num * sign));
}

// check duplicates in array of ints
static int	has_duplicate(int *arr, int n)
{
	int	i, j;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (arr[i] == arr[j])
				return (1);
	return (0);
}

// push value to bottom of stack
static void	push_back(t_stack *a, int val)
{
	t_node	*node = malloc(sizeof(t_node));
	if (!node) return ;
	node->val = val;
	node->idx = -1;
	node->next = NULL;
	node->prev = a->bottom;
	if (a->bottom)
		a->bottom->next = node;
	else
		a->top = node;
	a->bottom = node;
	a->size++;
}

// ---------- required funcs ----------

static int	count_numbers(int ac, char **av)
{
	int	i, j, count;

	count = 0;
	for (i = 1; i < ac; i++)
	{
		j = 0;
		while (av[i][j])
		{
			if ((j == 0 || av[i][j - 1] == ' ') && av[i][j] != ' ')
				count++;
			j++;
		}
	}
	return (count);
}

static int	fill_stack_from_args(int ac, char **av, t_stack *a, int *tmp)
{
	int		i, j, val, ok, count;
	char	**split;

	count = 0;
	for (i = 1; i < ac; i++)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (0);
		for (j = 0; split[j]; j++)
		{
			ok = 1;
			val = ps_atoi(split[j], &ok);
			if (!ok)
				return (ft_free_split(split), 0);
			tmp[count++] = val;
			push_back(a, val);
		}
		ft_free_split(split);
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


// check if stack a is sorted ascending
int	is_sorted(const t_stack *a)
{
	t_node	*cur = a->top;

	while (cur && cur->next)
	{
		if (cur->val > cur->next->val)
			return (0);
		cur = cur->next;
	}
	return (1);
}

// free everything
void	free_all(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	while (a && a->top)
	{
		tmp = a->top->next;
		free(a->top);
		a->top = tmp;
	}
	while (b && b->top)
	{
		tmp = b->top->next;
		free(b->top);
		b->top = tmp;
	}
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

// print Error and exit
void	error_exit(t_stack *a, t_stack *b)
{
	free_all(a, b);
	write(2, "Error\n", 6);
	exit(1);
}
