/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:48:18 by mfassad           #+#    #+#             */
/*   Updated: 2025/07/07 10:18:51 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

int	ft_put_ptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr >= 16)
	{
		count += ft_put_ptr(ptr / 16);
		count += ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			count += ft_putchar(ptr + '0');
		else
			count += ft_putchar(ptr - 10 + 'a');
	}
	return (count);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		count += ft_put_ptr(ptr);
	}
	return (count);
}
