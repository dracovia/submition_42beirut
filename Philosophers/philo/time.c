/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:37:03 by mfassad           #+#    #+#             */
/*   Updated: 2026/02/01 12:47:57 by mfassad          ###   ########.fr       */
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
int 	check_stop(t_data *data)
{
	int		stop;

	pthread_mutex_lock(&data->stop_mutex);
	stop = data->stop;
	pthread_mutex_unlock(&data->stop_mutex);
	if (stop)
		return 1;
	return 0;
}
void	smart_sleep(long duration, t_data *data)
{
	long	start;

	start = get_timestamp_ms();
	while (!check_stop(data))
	{
		if (get_timestamp_ms() - start >= duration)
			break ;
		usleep(500);
	}
}
