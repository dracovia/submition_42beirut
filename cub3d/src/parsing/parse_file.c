/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 15:22:32 by mfassad           #+#    #+#             */
/*   Updated: 2026/08/12 17:44:38 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
parse_file()
    │
    ├── open file
    │
    ├── get_next_line
    │
    ├── identify line
    │
    ├── parse texture
    │
    ├── parse color
    │
    ├── store map
    │
    └── close file
*/
#include "cub3d.h"

static int	is_texture(t_line_type type)
{
	return (type == LINE_NO || type == LINE_SO
		|| type == LINE_WE || type == LINE_EA);
}

static int	is_color(t_line_type type)
{
	return (type == LINE_F || type == LINE_C);
}

static int	handle_line(char *line, t_config *config)
{
	t_line_type	type;

	type = identify_line(line);
	if (type == LINE_INVALID)
		return (0);
	if (is_texture(type))
		return (parse_texture(line, type, config));
	if (is_color(type))
		return (parse_color(line, type, config));
	return (1);
}

int	parse_file(char *filename, t_config *config)
{
	char	**lines;
	int		i;

	lines = read_file(filename);
	if (!lines)
		return (0);
	i = 0;
	while (lines[i])
	{
		if (!handle_line(lines[i], config))
		{
			free_lines(lines);
			return (0);
		}
		i++;
	}
	free_lines(lines);
	return (1);
}
