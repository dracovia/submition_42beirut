/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 22:11:34 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/31 15:46:45 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

static int	ft_atoi(const char *s, int *ok)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -1;
	if (!*s)
		return (*ok = 0, 0);
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

int	is_sorted(const t_stack *a)
{
	t_node	*cur;

	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->val > cur->next->val)
			return (0);
		cur = cur->next;
	}
	return (1);
}

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
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	error_exit(t_stack *a, t_stack *b)
{
	free_all(a, b);
	write(2, "Error\n", 6);
	exit(1);
}
