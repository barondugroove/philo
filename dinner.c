/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:11:18 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/15 18:20:36 by bchabot          ###   ########.fr       */
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
	pthread_mutex_unlock(&philo->my_fork);
	pthread_mutex_unlock(philo->your_fork);
}

void	sleeping(t_philo *philo)
{
	print_message(philo, "is sleeping.");
	usleep(philo->data->tt_sleep * 1000);
}

void	*life(void *philo)
{
	t_philo	*p;
//	int		i;

	p = philo;
//	i = 0;
	if (p->my_id % 2 == 0)
		usleep(500);
	while (!p->data->is_dead) //&& p->data->replete < p->data->nbr_philo)
	{
		print_message(philo, "is thinking.");
	//	if (i < p->data->max_eat_nbr || p->data->max_eat_nbr == 0)
	//	{
			eating(p);
	//		i++;
	//	}
	//	else
	//		p->data->replete++;
		sleeping(p);
	}
	return (NULL);
}
