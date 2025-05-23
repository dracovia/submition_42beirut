/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:09:24 by mfassad           #+#    #+#             */
/*   Updated: 2025/05/23 09:11:10 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int					i;
	unsigned char		*p;
	const unsigned char	*s;

	i = 0;
	p = (unsigned char *) dst;
	s = (const unsigned char *) src;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	return (dst);
}
