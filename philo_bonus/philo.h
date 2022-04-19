/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 03:04:34 by ael-korc          #+#    #+#             */
/*   Updated: 2022/04/10 03:47:01 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/wait.h>
# include <pthread.h>
# include <stdio.h>
# define ERROR -1
# define SUCCESS 0
# define INFINITE_LOOP -1
# define DIE 4
# define SEM1 "fork"
# define SEM2 "check"

typedef struct s_philosopher
{
	long			time_last_meal;
	int				id;
	int				nb_meal;
	long			t_start;
	long			t_now;
	int				pid;
	pthread_t		thread;
}					t_philosopher;

typedef struct s_info
{
	int				count;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	t_philosopher	*philosopher;
	int				limit_nb_meal;
	sem_t			*fork;
	sem_t			*check;

}					t_info;

t_info	g_info;

int					ft_atoi(const char *nptr);
int					str_is_digit(char *str);
int					parsing(int nb_arg, char **arg);
long				get_actuel_time(void);
int					cycle_philosopher(void *ptr);
void				init_philosopher(t_philosopher philo[], int nb_philo);
void				init_semaphor(t_info *info);
void				clear_semaphor(t_info *info);
#endif
