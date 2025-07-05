/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:49:47 by mfassad           #+#    #+#             */
/*   Updated: 2025/07/05 10:49:47 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_unsigned_len(unsigned int n)
{
    int len = 0;

    if (n == 0)
        return (1);
    while (n)
    {
        n /= 10;
        len++;
    }
    return (len);
}

char *ft_uitoa(unsigned int n)
{
    int len = ft_unsigned_len(n);
    char *str;

    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (n == 0)
        str[0] = '0';
    while (n)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    return (str);
}

int ft_print_unsigned(unsigned int n)
{
    char *str;
    int printed_len;

    str = ft_uitoa(n);
    if (!str)
        return (0);
    printed_len = ft_print_str(str);
    free(str);
    return (printed_len);
}
