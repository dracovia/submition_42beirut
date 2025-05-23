/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:57:39 by mfassad           #+#    #+#             */
/*   Updated: 2025/05/23 09:00:08 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, int len)
{
	int				i;
	unsigned char	*p;

	i = 0 ;
	p = (unsigned char *)b;
	while (i < len)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, int n)
{
	ft_memset(s, 0, n);
}
