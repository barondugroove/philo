/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:34:39 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/15 18:45:49 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*undertaker(void *philos)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = philos;
	while (1)
	{
		pthread_mutex_lock(&p[i].data->reaper);
		if ((p[i].tl_meal + p[i].data->tt_die) <= get_time())
		{
			p[i].data->is_dead = 1;
			pthread_mutex_unlock(&p[i].data->reaper);
			printf("%lld %d %s\n", (get_time() - p->data->start), p[i].my_id, "died.");
			break ;
		}
		pthread_mutex_unlock(&p[i].data->reaper);
		if (i <= p[i].data->nbr_philo)
			i = 0;
		else
			i++;
	}
	return (NULL);
}

int	death(t_philo *philos)
{
	pthread_t		death_id;

	pthread_create(&death_id, NULL, &undertaker, philos);
	pthread_join(death_id, NULL);
	return (1);
}
