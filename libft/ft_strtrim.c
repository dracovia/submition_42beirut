/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 10:49:37 by mfassad           #+#    #+#             */
/*   Updated: 2025/05/25 10:49:37 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int is_in(char c, char const *set)
{
    int i;

    i = 0;
    while (set[i])
    {
        if (c == set[i])
            return (1);
        i++;
    }
    return (0);
}
int get_len(char const *s1, char const *set, size_t *start, size_t *end)
{
    size_t i;

    i = 0;
    while (s1[*start] && is_in(s1[*start], set))
        (*start)++;
    while ((*end) > (*start) && is_in(s1[(*end) - 1], set))
        (*end)--;
    return (*end - *start);
}
char *ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    char *str;
    size_t i;
    size_t end;

    if (!s1 || !set)
        return (NULL);
    end = ft_strlen(s1);
    start = 0;
    if (end == 0)
        return (char *)malloc(1);
    str = (char *)malloc(sizeof(char) * (get_len(s1, set, &start, &end) + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (start < end)
        str[i++] = s1[start++];
    str[i] = '\0';
    return (str);
}
