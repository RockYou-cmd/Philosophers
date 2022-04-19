/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 03:50:41 by ael-korc          #+#    #+#             */
/*   Updated: 2022/04/18 03:34:57 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include "philo.h"

void	detach_all_threads(t_philosopher philosopher[])
{
	int			id;

	id = -1;
	while (++id < g_info.nb_philo)
	{
		pthread_detach(philosopher[id].thread);
	}
	id = g_info.philo_dead;
	printf("Die id %d | time %ld\n", id, g_info.time_actuel);
}

void	join_all_thread(t_philosopher philosopher[])
{
	int			id;
	int			ret;

	id = -1;
	while (++id < g_info.nb_philo)
	{
		ret = pthread_join(philosopher[id].thread, NULL);
		if (ret)
			printf("Failed to join thread\n");
	}
	printf("Every one has eaten enought\n");
}

int	launch_threads(t_philosopher *philo, int id)
{
	int			ret;

	while (id < g_info.nb_philo)
	{
		ret = pthread_create(&philo[id].thread, NULL,
				cycle_philosopher, &philo[id]);
		if (ret)
		{
			printf("Error create thread of philosopher\n");
			return (ERROR);
		}
		usleep(1000);
		id++;
	}
	return (ret);
}

int	start_thread(int nb_philosopher)
{
	int					ret;
	t_philosopher		*philosopher;

	ret = 0;
	philosopher = malloc(nb_philosopher * sizeof(t_philosopher));
	g_info.fork = malloc(nb_philosopher * sizeof(pthread_mutex_t));
	init_philosopher(philosopher, nb_philosopher);
	if (init_mutex (g_info.fork))
		return (ret);
	if (launch_threads(&philosopher[0], 0) == ERROR)
		return (ERROR);
	usleep(1000);
	ret = check_is_alive(philosopher);
	if (ret == EVERY_ONE_HAS_EAT_ENOUGHT)
		join_all_thread(philosopher);
	if (ret == DIE)
		detach_all_threads(philosopher);
	ret = clear_mutex();
	return (ret);
}

int	main(int nb_arg, char **argument)
{
	if (parsing(nb_arg, argument) == ERROR)
		return (ERROR);
	else
		return (start_thread(g_info.nb_philo));
}
