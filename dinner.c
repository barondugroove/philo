/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:11:18 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/09 20:08:00 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->my_fork);
	pthread_mutex_lock(&philo->your_fork);
	print_message(philo, " is eating.");
	philo->tl_meal = get_time();
	usleep(philo->data->tt_eat);
	pthread_mutex_unlock(&philo->my_fork);
	pthread_mutex_unlock(&philo->your_fork);
}

void	sleeping(t_philo *philo)
{
	usleep(philo->data->tt_sleep);
	print_message(philo, " is sleeping.");
}

void	*life(void *philo)
{
	t_philo	*p;

	p = philo;
	print_message(philo, " is thinking.");
	eating(p);
	sleeping(p);
	return (NULL);
}
