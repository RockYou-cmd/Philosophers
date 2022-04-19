/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:39:23 by ael-korc          #+#    #+#             */
/*   Updated: 2022/04/10 03:44:25 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch_process(t_philosopher *philosopher)
{
	int					id;
	pid_t				pid;

	id = -1;
	while (++id < g_info.nb_philo)
	{
		philosopher[id].time_last_meal = get_actuel_time();
		pid = fork();
		if (pid < 0)
		{
			printf("error on fork");
			return (ERROR);
		}
		else if (!pid)
		{
			cycle_philosopher(&philosopher[id]);
			usleep(1000);
		}
	}
	waitpid(pid, NULL, 0);
	printf("\033[0;32m" "Every one has eaten enought\n");
	return (SUCCESS);
}

int	start_process(int nb)
{
	int					ret;
	t_philosopher		philos[1000];

	ret = 0;
	init_philosopher(philos, nb);
	init_semaphor(&g_info);
	ret = launch_process(&philos[0]);
	clear_semaphor(&g_info);
	return (ret);
}

int	main(int nb_arg, char **argument)
{
	if (parsing(nb_arg, argument) == ERROR)
		return (ERROR);
	else
		return (start_process(g_info.nb_philo));
}
