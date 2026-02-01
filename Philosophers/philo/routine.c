/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:41:41 by mfassad           #+#    #+#             */
/*   Updated: 2026/02/01 14:34:59 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   routine.c                                                               */
/*                                                                            */
/*   Responsibilities:                                                        */
/*   - Define the philosopher life routine                                    */
/*   - Implement eat, sleep, think cycle                                      */
/*   - Handle fork locking order                                              */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int check_stop(t_data *data)
{
    int stop;

    pthread_mutex_lock(&data->stop_mutex);
    stop = data->stop;
    pthread_mutex_unlock(&data->stop_mutex);
    return (stop);
}
static void take_forks(t_philo *p)
{
    if (p->id % 2 == 0)
    {
        pthread_mutex_lock(p->right_fork);
        print_state(p, "has taken a fork");
        pthread_mutex_lock(p->left_fork);
    }
    else
    {
        pthread_mutex_lock(p->left_fork);
        print_state(p, "has taken a fork");
        pthread_mutex_lock(p->right_fork);
    }
    print_state(p, "has taken a fork");
}

static void eat(t_philo *p)
{
    take_forks(p);
    pthread_mutex_lock(&p->data->meal_mutex);
    p->last_meal = get_timestamp_ms();
    print_state(p, "is eating");
    pthread_mutex_unlock(&p->data->meal_mutex);
    smart_sleep(p->data->time_eat, p->data);
    pthread_mutex_unlock(p->left_fork);
    pthread_mutex_unlock(p->right_fork);
    p->meals_eaten++;
}

void *philo_routine(void *arg)
{
    t_philo *p;

    p = (t_philo *)arg;
    if (p->id % 2)
        usleep(p->data->time_eat * 1000 / 2);
    if (p->data->philo_count == 1)
    {
        pthread_mutex_lock(p->left_fork);
        print_state(p, "has taken a fork");
        while (!check_stop(p->data))
            usleep(1000);
        pthread_mutex_unlock(p->left_fork);
        return (NULL);
    }
    while (!check_stop(p->data))
    {
        eat(p);
        print_state(p, "is sleeping");
        smart_sleep(p->data->time_sleep, p->data);
        print_state(p, "is thinking");
        usleep(1000);
    }
    return (NULL);
}
