/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:30:23 by mfassad           #+#    #+#             */
/*   Updated: 2026/02/08 15:13:25 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	launch_threads(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_create(&philos[i].thread, NULL,
			philo_routine, &philos[i]);
		i++;
	}
}

static void	join_threads(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philos;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	parse_args(ac, av, data);
	if (init_mutexes(data))
		return (1);
	philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!philos)
		return (1);
	data->start_time = get_timestamp_ms();
	init_philosophers(data, philos);
	launch_threads(data, philos);
	monitor_philosophers(data, philos);
	join_threads(data, philos);
	free(philos);
	destroy_mutexes(data);
	free(data);
	return (0);
}
