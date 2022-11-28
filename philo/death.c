/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:34:39 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/22 17:04:01 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*undertaker(void *philos)
{
	t_philo	*p;
	int		i;

	p = philos;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&p[i].data->reaper);
		if (p[i].tn_meal <= get_time())
		{
			pthread_mutex_unlock(&p[i].data->reaper);
			print_message(&p[i], "died");
			set_death(&p[i]);
			break ;
		}
		pthread_mutex_unlock(&p[i].data->reaper);
		if (i == p[i].data->nbr_philo - 1)
			i = 0;
		else
			i++;
	}
	return (NULL);
}

void	death(t_philo *philos)
{
	pthread_t		death_id;

	pthread_create(&death_id, NULL, &undertaker, philos);
	pthread_join(death_id, NULL);
	return ;
}
