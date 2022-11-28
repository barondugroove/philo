/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:26:12 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/28 20:11:58 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_data {
	int				is_dead;
	int				replete;
	long long		start;
	int				nbr_philo;
	long long		tt_die;
	long long		tt_eat;
	long long		tt_sleep;
	int				max_eat_nbr;
	pthread_mutex_t	print;
	pthread_mutex_t	reaper;
	pthread_mutex_t	eat_count;
}	t_data;

typedef struct s_philo {
	int				my_id;
	long long		tn_meal;
	pthread_mutex_t	my_fork;
	pthread_mutex_t	*your_fork;
	t_data			*data;
}	t_philo;

// CHECK_ERRORS
int			check_args_errors(char **av);

// DEATH
void		death(t_philo *philos);
void		*undertaker(void *philos);

// DINNER
void		*life(void *philo);
void		sleeping(t_philo *philo);
void		eating(t_philo *philo);

// PARSING
void		parse_data(t_data *data, char **av);
void		init_data(t_philo *philo, t_data *data);

// GETSET_DATA
int			get_death(t_philo *philo);
int			get_replete(t_philo *philo);
void		set_eat_count(t_philo *philo, int miam);
void		set_death(t_philo *philo);

// PHILO_UTILS
void		print_message(t_philo *philo, char *msg);
long long	get_time(void);
int			ft_atoi(const char *nptr);

// THREADS
void		create_threads(t_philo *philos, pthread_t *threads_id, int nbr);
void		join_threads(pthread_t *threads_id, int nbr);
void		destroy_mutex(t_philo *philos, int nbr);

#endif
