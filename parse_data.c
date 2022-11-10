/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:15:45 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/10 19:16:57 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->print, NULL);
	while (i < data->nbr_philo)
	{
		philo[i].data = data;
		philo[i].my_id = i + 1;
		philo[i].tl_meal = 0;
		philo[i].is_dead = 0;
		pthread_mutex_init(&philo[i].my_fork, NULL);
		if (i != 0)
			philo[i].your_fork = &philo[i - 1].my_fork;
		i++;
	}
	philo[0].your_fork = &philo[i - 1].my_fork;
}

void	parse_data(t_data *data, char **av)
{
	data->time = get_time();
	data->nbr_philo = ft_atoi(av[1]);
	data->tt_die = ft_atoi(av[2]);
	data->tt_eat = ft_atoi(av[3]);
	data->tt_sleep = ft_atoi(av[4]);
	if (av[5])
		data->max_eat_nbr = ft_atoi(av[5]);
	else
		data->max_eat_nbr = 0;
}
