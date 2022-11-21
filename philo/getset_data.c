/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:11:10 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/21 20:41:36 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_death(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->data->reaper);
	i = 0;
	if (philo->data->is_dead)
		i = 1;
	pthread_mutex_unlock(&philo->data->reaper);
	return (i);
}

int	get_replete(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->data->eat_count);
	i = 0;
	if (philo->data->replete == philo->data->nbr_philo)
		i = 1;
	pthread_mutex_unlock(&philo->data->eat_count);
	return (i);
}

void	set_eat_count(t_philo *philo, int miam)
{
	pthread_mutex_lock(&philo->data->eat_count);
	if (miam == philo->data->max_eat_nbr)
		philo->data->replete++;
	pthread_mutex_unlock(&philo->data->eat_count);
	return ;
}

void	set_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->reaper);
	philo->data->is_dead = 1;
	pthread_mutex_unlock(&philo->data->reaper);
	return ;
}
