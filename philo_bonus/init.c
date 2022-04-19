/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:39:13 by ael-korc          #+#    #+#             */
/*   Updated: 2022/04/10 03:20:35 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

void	init_philosopher(t_philosopher philolosopher[], int nb_philo)
{
	int			id;

	id = -1;
	while (++id < nb_philo)
	{
		memset(&philolosopher[id], 0, sizeof(t_philosopher));
		philolosopher[id].id = id + 1;
	}
}

void	init_semaphor(t_info *info)
{
	sem_unlink(SEM1);
	sem_unlink(SEM2);
	info->fork = sem_open(SEM1, O_CREAT, 777, info->nb_philo / 2);
	info->check = sem_open(SEM2, O_CREAT, 777, 1);
}

void	clear_semaphor(t_info *info)
{
	sem_close(info->fork);
	sem_close(info->check);
}
