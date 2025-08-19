/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 21:23:29 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/18 21:23:29 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int power_of_two(int exp)
{
    int result = 1;
    while (exp > 0)
    {
        result *= 2;
        exp--;
    }
    return result;
}

void radix_sort(t_stack *a, t_stack *b)
{
    int max_num;
    int max_bits;
    int i;
    int j;

    max_num = a->size - 1;
    max_bits = 0;
    while (max_num / power_of_two(max_bits) != 0)
        max_bits++;
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < a->size)
        {
            int bit = (a->top->val / power_of_two(i)) % 2;
            if (bit == 0)
                pb(a, b);    
            else
                ra(a);        
            j++;
        }
        while (b->size > 0)
            pa(a, b);        
        i++;
    }
}

