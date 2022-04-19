/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_philosopher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 03:49:11 by ael-korc          #+#    #+#             */
/*   Updated: 2022/04/18 03:28:46 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	state_of_philosopher(t_philosopher philosopher)
{
	long			time_actuel;

	time_actuel = get_actuel_time();
	if (g_info.current_number_of_meals == g_info.limit_nb_meal)
		return (EVERY_ONE_HAS_EAT_ENOUGHT);
	else if ((time_actuel - philosopher.time_last_meal) >= g_info.time_to_die)
	{
		g_info.time_actuel = time_actuel;
		g_info.philo_dead = philosopher.id;
		return (DIE);
	}
	return (0);
}

int	check_is_alive(t_philosopher philosopher[])
{
	int				id;
	int				ret;

	while (1)
	{
		id = -1;
		while (++id < g_info.nb_philo)
		{
			ret = state_of_philosopher(philosopher[id]);
			if (ret == DIE || ret == EVERY_ONE_HAS_EAT_ENOUGHT)
			{
				return (ret);
			}
		}
		usleep(500);
	}
	return (ret);
}

void	philosopher_eat(t_philosopher *philosopher)
{
	int				right;
	int				left;

	right = philosopher->right;
	left = philosopher->left;
	pthread_mutex_lock(&g_info.fork[right]);
	printf("%ld %d has taken a fork\n", get_actuel_time(), philosopher->id);
	pthread_mutex_lock(&g_info.fork[left]);
	printf("%ld %d has taken a fork\n", get_actuel_time(), philosopher->id);
	printf("%ld %d is eating \n", get_actuel_time(), philosopher->id);
	philosopher->time_last_meal = get_actuel_time();
	usleep(g_info.time_to_eat * 1000);
	pthread_mutex_unlock(&g_info.fork[right]);
	pthread_mutex_unlock(&g_info.fork[left]);
}

void	philosopher_sleep_and_think(t_philosopher *philosopher)
{
	printf("%ld %d is sleeping\n", get_actuel_time(), philosopher->id);
	usleep(g_info.time_to_sleep * 1000);
	printf("%ld %d is thinking\n", get_actuel_time(), philosopher->id);
}

void	*cycle_philosopher(void *ptr)
{
	int				loop;
	t_philosopher	*philosopher;

	loop = g_info.limit_nb_meal;
	philosopher = (t_philosopher *)ptr;
	philosopher->time_last_meal = get_actuel_time();
	while (loop)
	{
		philosopher_eat(philosopher);
		philosopher_sleep_and_think(philosopher);
		if (loop != INFINITE_LOOP)
			loop--;
	}
	g_info.current_number_of_meals = g_info.limit_nb_meal;
	return (0);
}
