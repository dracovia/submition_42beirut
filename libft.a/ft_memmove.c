/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:11:19 by mfassad           #+#    #+#             */
/*   Updated: 2025/05/23 09:15:39 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int					i;
	unsigned char		*p;
	const unsigned char	*s;

	i = 0;
	p = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, int len)
{
	unsigned char		*d;
	const unsigned char	*s;
	int					i;

	i = len - 1;
	d = dst;
	s = src;
	if (s == d || len == 0)
		return (dst);
	if (d < s)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (d);
}
