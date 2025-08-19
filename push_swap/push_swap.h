/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 22:05:17 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/17 22:05:17 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int             val;
	int             idx;    // compressed index for sorting
	struct s_node  *prev;
	struct s_node  *next;
}   t_node;

typedef struct s_stack
{
	t_node  *top;       // first element (stack "top")
	t_node  *bottom;    // last element (stack "bottom")
	int     size;
	char    name;       // 'a' or 'b' (optional, useful for debugging)
}   t_stack;


int   parse_args_to_stack(int ac, char **av, t_stack *a);
int   is_sorted(const t_stack *a);
void  free_all(t_stack *a, t_stack *b);
void  error_exit(t_stack *a, t_stack *b);

void  op_sa(t_stack *a);
void  op_sb(t_stack *b);
void  op_ss(t_stack *a, t_stack *b);
void  op_pa(t_stack *a, t_stack *b);
void  op_pb(t_stack *a, t_stack *b);
void  op_ra(t_stack *a);
void  op_rb(t_stack *b);
void  op_rr(t_stack *a, t_stack *b);
void  op_rra(t_stack *a);
void  op_rrb(t_stack *b);
void  op_rrr(t_stack *a, t_stack *b);

void  compress_to_indices(t_stack *a); 
void  sort_small(t_stack *a, t_stack *b);  
void  radix_sort(t_stack *a, t_stack *b);