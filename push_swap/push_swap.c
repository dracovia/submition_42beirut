/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:39:28 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/18 22:39:28 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    t_stack a;
    t_stack b;

    a.top = NULL;
    a.bottom = NULL;
    a.size = 0;
    b.top = NULL;
    b.bottom = NULL;
    b.size = 0;
    if (ac < 2)
        return 0;
    if (!parse_args_to_stack(ac, av, &a))
    {
        write(2, "Error\n", 6);
        return 1;
    }
    if (is_sorted(&a))
    {
        free_all(&a, &b);
        return 0;
    }
    compress_to_indices(&a);
    if (a.size <= 5)
        sort_small(&a, &b);
    else
        radix_sort(&a, &b);
    free_all(&a, &b);
    return 0;
}
