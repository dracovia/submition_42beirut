/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:14:19 by mfassad           #+#    #+#             */
/*   Updated: 2025/07/07 10:03:04 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>   
# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		ft_formats(va_list args, const char format);

int		ft_print_char(char c);
int		ft_print_str(char *str);

int		ft_print_ptr(unsigned long ptr);
int		ft_put_ptr(unsigned long ptr);
int		ft_ptr_len(unsigned long ptr);

int		ft_print_int(int n);
char	*ft_itoa(int n);

int		ft_print_unsigned(unsigned int n);
char	*ft_uitoa(unsigned int n);

int		ft_print_hex(unsigned int n, const char format);
void	ft_put_hex(unsigned int n, const char format);
int		ft_hex_len(unsigned int n);

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_num_len(int n);
int		ft_unsigned_len(unsigned int n);

#endif
