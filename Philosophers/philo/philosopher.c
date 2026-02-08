/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:40:18 by mfassad           #+#    #+#             */
/*   Updated: 2026/02/08 15:45:56 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philosophers(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	if (!data || !data->forks || !philos)
		return (1);
	while (i < data->philo_count)
	{
		philos[i].id = i + 1;
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[(i + 1)
			% data->philo_count];
		philos[i].last_meal = data->start_time;
		philos[i].meals_eaten = 0;
		philos[i].data = data;
		i++;
	}
	return (0);
}
