/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 05:31:07 by ael-korc          #+#    #+#             */
/*   Updated: 2022/04/10 07:25:49 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clear_mutex(void)
{
	int				ret;
	int				id;

	id = -1;
	while (++id < g_info.nb_philo)
		ret = pthread_mutex_destroy(&g_info.fork[id]);
	ret = pthread_mutex_destroy(&g_info.eat);
	free(g_info.fork);
	return (ret);
}

long	get_actuel_time(void)
{
	long			ret;
	struct timeval	t1;

	ret = 0;
	gettimeofday(&t1, NULL);
	ret = t1.tv_sec * 1000;
	ret += t1.tv_usec / 1000;
	return (ret);
}
