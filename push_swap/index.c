/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 21:23:16 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/18 21:23:16 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	*copy_val(t_stack *a)
{
	int		*arr;
	int		i;
	t_node	*curr;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	curr = a->top;
	i = 0;
	while (i < a->size)
	{
		arr[i] = curr->val;
		curr = curr->next;
		i++;
	}
	return (arr);
}

void	compress_to_indices(t_stack *a)
{
	int		*sorted;
	t_node	*curr;
	int		i;

	sorted = copy_val(a);
	if (!sorted)
		return ;
	sort_array(sorted, a->size);
	curr = a->top;
	while (curr)
	{
		i = 0;
		while (i < a->size)
		{
			if (curr->val == sorted[i])
			{
				curr->idx = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
	free(sorted);
}
