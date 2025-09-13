/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:43:02 by mfassad           #+#    #+#             */
/*   Updated: 2025/09/13 10:43:07 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

static size_t	count_words(const char *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != ' ')
			i++;
	}
	return (count);
}

static char	*dup_word(const char *s, size_t start, size_t len)
{
	char	*word;
	size_t	t;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	t = 0;
	while (t < len)
	{
		word[t] = s[start + t];
		t++;
	}
	word[t] = '\0';
	return (word);
}

static int	add_word(const char *s, char **res, size_t *i, size_t *k)
{
	size_t	j;
	size_t	len;

	while (s[*i] && s[*i] == ' ')
		(*i)++;
	if (!s[*i])
		return (0);
	j = *i;
	while (s[j] && s[j] != ' ')
		j++;
	len = j - *i;
	res[*k] = dup_word(s, *i, len);
	if (!res[*k])
		return (-1);
	(*k)++;
	*i = j;
	return (1);
}

char	**ft_split_spaces(const char *s)
{
	char	**res;
	size_t	i;
	size_t	k;
	int		status;

	if (!s)
		return (NULL);
	res = malloc((count_words(s) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		status = add_word(s, res, &i, &k);
		if (status == -1)
			return (ft_free_split(res), NULL);
		if (status == 0)
			break ;
	}
	res[k] = NULL;
	return (res);
}
