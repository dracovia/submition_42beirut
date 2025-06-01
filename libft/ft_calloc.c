/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:00:18 by mfassad           #+#    #+#             */
/*   Updated: 2025/05/29 16:05:34 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdint.h>

void *ft_calloc(size_t nmemb, size_t size)
{
	size_t total_size; 

	if (nmemb == 0 || size == 0)
	{
		return malloc(0);
	}
	if (size > SIZE_MAX / nmemb)
	{
		return NULL;
	}
	total_size = nmemb * size;
	void *ptr = malloc(total_size);
	if (!ptr)
	{
		return NULL;
	}
	memset(ptr, 0, total_size);
	return ptr;
}
