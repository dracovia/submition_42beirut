/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:36:49 by mfassad           #+#    #+#             */
/*   Updated: 2026/02/01 15:09:48 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   print.c                                                                  */
/*                                                                            */
/*   Responsibilities:                                                        */
/*   - Print philosopher state changes                                        */
/*   - Protect output with a mutex                                            */
/*   - Ensure no overlapping or late messages                                 */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include "philo.h"

void	print_state(t_philo *philo, char *msg)
{
	long	time;

	pthread_mutex_lock(&philo->data->stop_mutex);
	if (philo->data->stop && msg[0] != 'd')
	{
		pthread_mutex_unlock(&philo->data->stop_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->stop_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	time = elapsed_time(philo->data);
	printf("%ld %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
