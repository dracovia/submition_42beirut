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

#include <unistd.h>
#include <stdarg.h>



int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;
	char *st;
	int dt;

	va_start(args, format);
	count = 0;
	while (format[count])
	{	
		if (format [count] == '%')
		{
			count++;
			if (format[count] == 's')
			{
				st = va_arg (args, char *);
				count += ft_putstr_fd(st, 2)
			}
			else if (format[count] == 'd')
			{
				st = va_arg (args, int);
				count += ft_putstr_fd(st, 2)
			}
		}
		write (2, &format[count], 1);
		count++;
	}

	va_end(args);
	return (count);
}
#include <stdio.h>

int main (void)
{
	int c = ft_printf("hello my name is " );
	printf ("%d",c);
}