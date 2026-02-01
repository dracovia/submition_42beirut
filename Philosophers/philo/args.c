/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:37:25 by mfassad           #+#    #+#             */
/*   Updated: 2026/01/23 19:18:36 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	error_exit(char *msg)
{
	write(2, "Error: ", 7);
	while (*msg)
		write(2, msg++, 1);
	write(2, "\n", 1);
	exit(1);
}

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		if (res > 2147483647)
			return (-1);
		i++;
	}
	return (res);
}

static void	check_args(int ac, char **av)
{
	int	i;

	if (ac != 5 && ac != 6)
		error_exit("Usage: ./philo n_philo t_die t_eat t_sleep [must_eat]");
	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
			error_exit("Arguments must be positive numbers");
		i++;
	}
}

int	parse_args(int ac, char **av, t_data *data)
{
	check_args(ac, av);
	data->philo_count = ft_atol(av[1]);
	data->time_die = ft_atol(av[2]);
	data->time_eat = ft_atol(av[3]);
	data->time_sleep = ft_atol(av[4]);
	data->must_eat = -1;
	if (ac == 6)
		data->must_eat = ft_atol(av[5]);
	if (data->philo_count < 1 || data->time_die <= 0
		|| data->time_eat <= 0 || data->time_sleep <= 0
		|| (ac == 6 && data->must_eat <= 0))
		error_exit("Invalid argument values");
	data->stop = 0;
	return (0);
}
