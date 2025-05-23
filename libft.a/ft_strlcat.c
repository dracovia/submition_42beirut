/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:20:56 by mfassad           #+#    #+#             */
/*   Updated: 2025/05/23 09:23:48 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i])
		i++;
	if (i == dstsize)
		return (dstsize + strlen(src));
	while (src[j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < dstsize)
		dst[i + j] = '\0';
	return (i + strlen(src));
}
