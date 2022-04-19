/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:39:43 by ael-korc          #+#    #+#             */
/*   Updated: 2022/04/10 03:47:49 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	str_is_digit(char *str)
{
	int				index;
	int				ret;

	index = -1;
	while (str[++index])
	{
		ret = ft_isdigit(str[index]);
		if (ret == 0)
			return (ERROR);
	}
	return (SUCCESS);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	box;

	i = 0;
	j = 1;
	box = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '+'
			|| str[i] == '-') && (str[i + 1] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		box = (box * 10) + (str[i] - '0');
		i++;
	}
	return (box * j);
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
