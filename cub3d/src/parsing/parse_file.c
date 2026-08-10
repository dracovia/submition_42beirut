/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 15:22:32 by mfassad           #+#    #+#             */
/*   Updated: 2026/08/10 16:41:34 by mfassad          ###   ########.fr       */
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

int	parse_file(char *filename, t_config *config)
{
	int	fd;

	(void)config;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nCould not open file\n", 26);
		return (0);
	}
	close(fd);
	return (1);
}