/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 15:22:32 by mfassad           #+#    #+#             */
/*   Updated: 2026/08/15 17:45:05 by mfassad          ###   ########.fr       */
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

static int	handle_config(char *line, t_line_type type,
		t_config *config, t_parse_state *state)
{
	if (type == LINE_EMPTY)
		return (1);
	if (is_texture(type))
		return (parse_texture(line, type, config));
	if (is_color(type))
		return (parse_color(line, type, config));
	if (type == LINE_MAP)
	{
		if (!config_complete(config))
			return (0);
		*state = PARSE_MAP;
		return (1);
	}
	return (0);
}

static int	handle_map(t_line_type type)
{
	if (type != LINE_MAP)
		return (0);
	return (1);
}

static int	handle_line(char *line, t_line_type type,
		t_config *config, t_parse_state *state)
{
	if (*state == PARSE_CONFIG)
		return (handle_config(line, type, config, state));
	return (handle_map(type));
}

int	parse_file(char *filename, t_config *config)
{
	t_parse_state	state;
	t_line_type		type;
	char			**lines;
	int				map_start;
	int				i;

	lines = read_file(filename);
	if (!lines)
		return (0);
	state = PARSE_CONFIG;
	map_start = -1;
	i = 0;
	while (lines[i])
	{
		type = identify_line(lines[i]);
		if (!handle_line(lines[i], type, config, &state))
		{
			free_lines(lines);
			return (0);
		}
		if (type == LINE_MAP && map_start == -1)
			map_start = i;
		i++;
	}
	if (!config_complete(config) || map_start == -1)
	{
		free_lines(lines);
		return (0);
	}
	if (!store_map(lines, map_start, config))
	{
		free_lines(lines);
		return (0);
	}
	free_lines(lines);
	return (1);
}
