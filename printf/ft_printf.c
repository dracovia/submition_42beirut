/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:19:09 by mfassad           #+#    #+#             */
/*   Updated: 2025/07/03 14:00:51 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_formats(va_list args, const char format)
{
    int count = 0;

    if (format == 'c')
        count += ft_print_char(va_arg(args, int));
    else if (format == 's')
        count += ft_print_str(va_arg(args, char *));
    else if (format == 'p')
        count += ft_print_ptr(va_arg(args, unsigned long));
    else if (format == 'd' || format == 'i')
        count += ft_print_int(va_arg(args, int));
    else if (format == 'u')
        count += ft_print_unsigned(va_arg(args, unsigned int));
    else if (format == 'x' || format == 'X')
        count += ft_print_hex(va_arg(args, unsigned int), format);
    else if (format == '%')
        count += ft_print_char('%');
    return (count);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int count = 0;

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            count += ft_formats(args, format[i + 1]);
            i += 2;
        }
        else
        {
            count += ft_print_char(format[i]);
            i++;
        }
    }
    va_end(args);
    return (count);
}
