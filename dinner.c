/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:11:18 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/16 18:37:15 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->my_fork);
	print_message(philo, "has taken a fork.");
	pthread_mutex_lock(philo->your_fork);
	print_message(philo, "has taken a fork.");
	pthread_mutex_lock(&philo->data->reaper);
	philo->tl_meal = get_time();
	pthread_mutex_unlock(&philo->data->reaper);
	print_message(philo, "is eating.");
	usleep(philo->data->tt_eat * 1000);
	pthread_mutex_unlock(philo->your_fork);
	pthread_mutex_unlock(&philo->my_fork);
}

void	sleeping(t_philo *philo)
{
	print_message(philo, "is sleeping.");
	usleep(philo->data->tt_sleep * 1000);
}

void	*life(void *philo)
{
	t_philo	*p;
	int		miam;

	p = philo;
	miam = 0;
	if (p->my_id % 2 == 0)
		usleep(500);
	while (1)
	{
		pthread_mutex_lock(&p->data->reaper);
		pthread_mutex_lock(&p->data->eat_count);
		if (p->data->is_dead || p->data->replete >= p->data->nbr_philo)
		{
			pthread_mutex_unlock(&p->data->reaper);
			pthread_mutex_unlock(&p->data->eat_count);
			break ;
		}
		pthread_mutex_unlock(&p->data->eat_count);
		pthread_mutex_unlock(&p->data->reaper);
		print_message(philo, "is thinking.");
		if (p->data->nbr_philo == 1)
		{
			pthread_mutex_lock(&p->my_fork);
			print_message(philo, "has taken a fork.");
			pthread_mutex_unlock(&p->my_fork);
			usleep(p->data->tt_die + 1);
			break ;
		}
		eating(p);
		miam++;
		pthread_mutex_lock(&p->data->eat_count);
		if (miam == p->data->max_eat_nbr)
			p->data->replete++;
		pthread_mutex_unlock(&p->data->eat_count);
		sleeping(p);
	}
	return (NULL);
}
