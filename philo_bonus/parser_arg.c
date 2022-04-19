/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:39:28 by ael-korc          #+#    #+#             */
/*   Updated: 2022/04/10 03:45:08 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_arg(char **arg)
{
	int			t_sleep;

	g_info.nb_philo = ft_atoi(arg[1]);
	g_info.time_to_die = ft_atoi(arg[2]);
	g_info.time_to_eat = ft_atoi(arg[3]);
	g_info.time_to_sleep = ft_atoi(arg[4]);
	if (arg[5])
		g_info.limit_nb_meal = ft_atoi(arg[5]);
	else
		g_info.limit_nb_meal = INFINITE_LOOP;
	if (g_info.nb_philo < 2)
		return (ERROR);
	t_sleep = g_info.time_to_sleep;
	if (g_info.time_to_die <= 0 || g_info.time_to_eat <= 0 || t_sleep <= 0)
		return (ERROR);
	return (SUCCESS);
}

int	check_arg(int nb_arg, char **arg)
{
	int			index;

	index = 0;
	if (nb_arg < 5 || nb_arg > 6)
	{
		printf("\033[0;31m" "argument number is bad\n");
		return (ERROR);
	}
	while (arg[++index])
	{
		if (str_is_digit(arg[index]) == ERROR)
		{
			printf("\033[0;31m" "Argument is not digit character\n");
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int	parsing(int nb_arg, char **arg)
{
	memset(&g_info, 0, sizeof(t_info));
	if (check_arg(nb_arg, arg) == ERROR)
		return (ERROR);
	if (get_arg(arg) == ERROR)
	{
		printf("\033[0;31m" "Error arguments\n");
		return (ERROR);
	}
	return (SUCCESS);
}
