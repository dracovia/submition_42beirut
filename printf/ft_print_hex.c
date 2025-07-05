/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:55:07 by mfassad           #+#    #+#             */
/*   Updated: 2025/07/05 12:55:07 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hex_len(unsigned int n)
{
    int len = 0;

    if (n == 0)
        return (1);
    while (n)
    {
        n /= 16;
        len++;
    }
    return (len);
}

void ft_put_hex(unsigned int n, const char format)
{
    if (n >= 16)
    {
        ft_put_hex(n / 16, format);
        ft_put_hex(n % 16, format);
    }
    else
    {
        if (n <= 9)
            ft_putchar(n + '0');
        else
        {
            if (format == 'x')
                ft_putchar(n - 10 + 'a');
            else if (format == 'X')
                ft_putchar(n - 10 + 'A'); 
        }
    }
}

int ft_print_hex(unsigned int n, const char format)
{
    ft_put_hex(n, format);
    return (ft_hex_len(n));
}
