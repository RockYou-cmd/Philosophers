/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 03:49:59 by ael-korc          #+#    #+#             */
/*   Updated: 2022/04/10 07:23:18 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philosopher(t_philosopher philo[], int nb_philo)
{
	int					id;

	id = -1;
	while (++id < nb_philo)
	{
		memset(&philo[id], 0, sizeof(t_philosopher));
		philo[id].id = id + 1;
		philo[id].right = id;
		philo[id].left = (id + 1) % g_info.nb_philo;
	}
}

int	init_mutex(pthread_mutex_t fork[])
{
	int					id;
	int					ret;

	id = -1;
	while (++id < g_info.nb_philo)
	{
		if ((pthread_mutex_init(&fork[id], NULL)))
		{
			printf("error init mutex\n");
			return (ERROR);
		}
	}
	ret = pthread_mutex_init(&g_info.eat, NULL);
	if (ret)
	{
		printf("error init mutex\n");
		return (ERROR);
	}
	return (SUCCESS);
}
