/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:34:39 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/09 20:14:45 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*undertaker(void *philos)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = philos;
	while (p[i].data->time - p[i].tl_meal < p[i].data->tt_die)
	{
		if (i < p[i].data->nbr_philo)
			i++;
		else
			i = 0;
	}
	print_message(&p[i], " is dead.");
	return (NULL);	//Return to main to join pthread
}

int	death(t_philo *philos)
{
	pthread_t	death_id;

	pthread_create(&death_id, NULL, &undertaker, &philos);
//	pthread_mutex_destroy(&death_id);
	return (1);
}
