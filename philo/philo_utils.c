/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:16:07 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/21 20:16:16 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *msg)
{
	t_philo	*p;

	p = philo;
	pthread_mutex_lock(&p->data->print);
	if (!get_death(p) && !get_replete(p))
		printf("%lld %d %s\n", (get_time() - p->data->start), p->my_id, msg);
	pthread_mutex_unlock(&p->data->print);
	return ;
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

int	ft_atoi(const char *nptr)
{
	long long int	nbr;
	int				neg;
	int				i;

	i = 0;
	neg = 1;
	nbr = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		neg *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	if ((nbr * neg) > 1000 || (nbr * neg) <= 0)
		return (-1);
	return (nbr * neg);
}
