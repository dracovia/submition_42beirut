/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:52:17 by mfassad           #+#    #+#             */
/*   Updated: 2026/01/23 22:21:04 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   philo.h                                                                  */
/*                                                                            */
/*   Responsibilities:                                                        */
/*   - Define all structs used in the project                                 */
/*   - Declare all shared function prototypes                                 */
/*   - Include required libraries (pthread, sys/time, stdio, etc.)            */
/*   - Centralize configuration and shared constants                           */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				philo_count;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	int				must_eat;

	long			start_time;
	int				stop;

	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	meal_mutex;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	long			last_meal;
	int				meals_eaten;

	t_data			*data;
}	t_philo;

int		parse_args(int ac, char **av, t_data *data);

long	get_timestamp_ms(void);
long	elapsed_time(t_data *data);
void	smart_sleep(long duration, t_data *data);

int		init_mutexes(t_data *data);
void	destroy_mutexes(t_data *data);

int		init_philosophers(t_data *data, t_philo *philos);

void	*philo_routine(void *arg);

void	monitor_philosophers(t_data *data, t_philo *philos);

void	print_state(t_philo *philo, char *msg);

#endif
