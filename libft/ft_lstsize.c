/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:07:58 by mfassad           #+#    #+#             */
/*   Updated: 2025/05/28 14:07:58 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int ft_lstsize(t_list *lst)
{
    t_list *temp;
    int   len;

    temp = lst;
    len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return (len);
}

