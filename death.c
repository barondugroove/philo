/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:34:39 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/10 19:23:12 by bchabot          ###   ########.fr       */
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
	p[i].is_dead = 1;
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
