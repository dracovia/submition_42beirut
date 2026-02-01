/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:37:03 by mfassad           #+#    #+#             */
/*   Updated: 2026/01/23 22:13:34 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*   time.c                                                                   */
/*                                                                            */
/*   Responsibilities:                                                        */
/*   - Provide timestamp utilities                                            */
/*   - Calculate elapsed time in milliseconds                                 */
/*   - Implement precise sleeping logic                                       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long	elapsed_time(t_data *data)
{
	return (get_timestamp_ms() - data->start_time);
}
void	smart_sleep(long duration, t_data *data)
{
	long	start;
	int		stop;

	start = get_timestamp_ms();
	while (1)
	{
		pthread_mutex_lock(&data->stop_mutex);
		stop = data->stop;
		pthread_mutex_unlock(&data->stop_mutex);
		if (stop || get_timestamp_ms() - start >= duration)
			break ;
		usleep(500);
	}
}
