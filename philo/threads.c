/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:16:01 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/22 15:54:22 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_philo *philos, pthread_t *threads_id, int nbr)
{
	int			i;

	i = 0;
	while (i < nbr)
	{
		pthread_create(&threads_id[i], NULL, &life, &philos[i]);
		i++;
	}
	return ;
}

void	join_threads(pthread_t *threads_id, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		pthread_join(threads_id[i], NULL);
		i++;
	}
	return ;
}

void	destroy_mutex(t_philo *philos, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		pthread_mutex_destroy(&philos[i].my_fork);
		i++;
	}
	pthread_mutex_destroy(&philos[0].data->print);
	pthread_mutex_destroy(&philos[0].data->reaper);
	pthread_mutex_destroy(&philos[0].data->eat_count);
	return ;
}
