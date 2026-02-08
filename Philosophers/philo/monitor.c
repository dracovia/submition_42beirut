/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 22:42:43 by mfassad           #+#    #+#             */
/*   Updated: 2026/02/08 14:54:00 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	all_ate_enough(t_data *data, t_philo *philos)
{
	int	i;
	int	done;

	if (data->must_eat == -1)
		return (0);
	i = 0;
	done = 1;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->meal_mutex);
		if (philos[i].meals_eaten < data->must_eat)
			done = 0;
		pthread_mutex_unlock(&data->meal_mutex);
		if (!done)
			return (0);
		i++;
	}
	return (1);
}

static void	set_stop(t_data *data)
{
	pthread_mutex_lock(&data->stop_mutex);
	data->stop = 1;
	pthread_mutex_unlock(&data->stop_mutex);
}

void	monitor_philosophers(t_data *data, t_philo *philos)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->philo_count)
		{
			pthread_mutex_lock(&data->meal_mutex);
			if (get_timestamp_ms() - philos[i].last_meal > data->time_die)
			{
				pthread_mutex_unlock(&data->meal_mutex);
				set_stop(data);
				print_state(&philos[i], "died");
				return ;
			}
			pthread_mutex_unlock(&data->meal_mutex);
			i++;
		}
		if (all_ate_enough(data, philos))
			return (set_stop(data));
		usleep(200);
	}
}
