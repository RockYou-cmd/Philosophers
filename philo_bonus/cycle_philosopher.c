/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_philosopher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:39:37 by ael-korc          #+#    #+#             */
/*   Updated: 2022/04/10 03:21:17 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>

void	*check_is_alive(void *ptr)
{
	t_philosopher		*philosopher;
	long				time_actuel;

	philosopher = (t_philosopher *)ptr;
	while (1)
	{
		sem_wait(g_info.check);
		time_actuel = get_actuel_time();
		if ((time_actuel - philosopher->time_last_meal) >= g_info.time_to_die)
		{
			printf("\033[0;31m" "philo %d  die | time %ld\n",
				philosopher->id, time_actuel);
			kill(0, SIGINT);
			return (0);
		}
		sem_post(g_info.check);
		usleep(1000);
	}
	return (0);
}

void	philosopher_eat(t_philosopher *philosopher)
{
	sem_wait(g_info.fork);
	printf("%ld %d has taken a fork\n", get_actuel_time(), philosopher->id);
	printf("%ld %d has taken a fork\n", get_actuel_time(), philosopher->id);
	philosopher->time_last_meal = get_actuel_time();
	printf("%ld %d is eating \n", philosopher->time_last_meal, philosopher->id);
	usleep(g_info.time_to_eat * 1000);
	sem_post(g_info.fork);
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	printf("%ld %d is sleeping\n", get_actuel_time(), philosopher->id);
	usleep(g_info.time_to_sleep * 1000);
}

int	cycle_philosopher(void *ptr)
{
	int					loop;
	t_philosopher		*philosopher;
	pthread_t			thread_id;

	loop = g_info.limit_nb_meal;
	philosopher = (t_philosopher *)ptr;
	pthread_create(&thread_id, NULL, check_is_alive, philosopher);
	while (loop != 0)
	{
		printf("%ld %d is thinking\n", get_actuel_time(), philosopher->id);
		philosopher_eat(philosopher);
		philosopher_sleep(philosopher);
		usleep(1000);
		if (loop != INFINITE_LOOP)
			loop--;
	}
	exit(0);
}
