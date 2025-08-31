/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:36:51 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/31 15:39:49 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_back(t_stack *a, int val)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return ;
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
