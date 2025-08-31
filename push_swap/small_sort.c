/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 21:23:46 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/31 15:55:50 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sort_small.c
#include "push_swap.h"

static void	sort_two(t_stack *a)
{
	if (a->top->val > a->top->next->val)
		sa(a);
}

static void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->val;
	y = a->top->next->val;
	z = a->bottom->val;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

static void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	t_node	*cur;
	int		pos;
	int		min_pos;
	int		min_val;

	cur = a->top;
	pos = 0;
	min_pos = 0;
	min_val = cur->val;
	while (cur)
	{
		if (cur->val < min_val)
		{
			min_val = cur->val;
			min_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	if (min_pos <= a->size / 2)
		while (min_pos--)
			ra(a);
	else
		while (min_pos++ < a->size)
			rra(a);
	pb(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
	{
		while (a->size > 3)
			push_smallest_to_b(a, b);
		sort_three(a);
		while (b->size)
			pa(a, b);
	}
}
