/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjaminchabot <benjaminchabot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:34:39 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/11 14:10:59 by benjamincha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*undertaker(void *philos)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = philos;
	while ((p[i].tl_meal + p[i].data->tt_die) <= get_time())
	{
		if (i < p[i].data->nbr_philo - 1)
			i++;
		else
			i = 0;
	}
	p[i].data->is_dead = 1;
	print_message(&p[i], " is dead.");
	return (NULL);
}

int	death(t_philo *philos)
{
	pthread_t	death_id;

	pthread_create(&death_id, NULL, &undertaker, philos);
	pthread_join(death_id, NULL);
	pthread_mutex_destroy(&philos->data->print);
	return (1);
}
