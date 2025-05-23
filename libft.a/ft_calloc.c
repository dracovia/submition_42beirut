/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:00:18 by mfassad           #+#    #+#             */
/*   Updated: 2025/05/23 09:01:45 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	if (count == 0 || size == 0)
		return (malloc(1));
	array = malloc(size * count);
	if (!array)
		return (NULL);
	ft_bzero(array, count * size);
	return (array);
}
