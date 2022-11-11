/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjaminchabot <benjaminchabot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:26:12 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/11 14:14:33 by benjamincha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PIPEX_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_data {
	int				is_dead;
	long int		time;
	int				nbr_philo;
	long int		tt_die;
	long int		tt_eat;
	long int		tt_sleep;
	int				max_eat_nbr;
	pthread_mutex_t	print;
}	t_data;

typedef struct s_philo {
	int				my_id;
	int				tl_meal;
	pthread_mutex_t	my_fork;
	pthread_mutex_t	*your_fork;
	t_data			*data;
}	t_philo;

void			parse_data(t_data *data, char **av);
void			init_data(t_philo *philo, t_data *data);
int				check_args_errors(char **av);
void			ft_putendl_fd(char *s, int fd);
int				ft_atoi(const char *nptr);
void			print_data(t_data *data, int i);
long int		get_time(void);
void			*life(void *philo);
void			print_message(t_philo *philo, char *msg);
int				death(t_philo *philos);

#endif
