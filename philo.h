/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:26:12 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/07 17:34:45 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PIPEX_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


typedef struct s_data {
	int		nbr_philo;
	int		tt_die;
	int		tt_eat;
	int		tt_sleep;
	int		max_eat_nbr;
}	t_data;

typedef struct s_philo {
	int		my_fork;
	int		tl_meal;
	int		is_eating;
	t_data	*data;
}	t_philo;

void	parse_data(t_data *data, char **av);
int		check_args_errors(char **av);
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *nptr);

#endif
