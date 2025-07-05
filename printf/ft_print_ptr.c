/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:48:18 by mfassad           #+#    #+#             */
/*   Updated: 2025/07/03 19:48:18 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_ptr_len(unsigned long ptr)
{
    int len = 0;

    if (ptr == 0)
        return (1);  
    while (ptr != 0)
    {
        ptr /= 16;
        len++;
    }
    return (len);
}

void ft_put_ptr(unsigned long ptr)
{
    if (ptr >= 16)
    {
        ft_put_ptr(ptr / 16);
        ft_put_ptr(ptr % 16);
    }
    else
    {
        if (ptr <= 9)
            ft_putchar(ptr + '0');
        else
            ft_putchar(ptr - 10 + 'a');  
    }
}

int ft_print_ptr(unsigned long ptr)
{
    int count = 0;

    count += write(1, "0x", 2);
    if (ptr == 0)
        count += write(1, "0", 1);
    else
    {
        ft_put_ptr(ptr);
        count += ft_ptr_len(ptr);
    }
    return (count);
}
