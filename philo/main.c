/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:10:58 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/22 15:55:41 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(char **av, t_data *data)
{
	t_philo		philos[256];
	pthread_t	threads_id[256];

	parse_data(data, av);
	init_data(philos, data);
	create_threads(philos, threads_id, data->nbr_philo);
	death(philos);
	if (data->nbr_philo == 1)
		pthread_mutex_unlock(&philos[0].my_fork);
	join_threads(threads_id, data->nbr_philo);
	destroy_mutex(philos, data->nbr_philo);
	return ;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac > 4 && ac <= 6)
	{
		if (check_args_errors(av))
			return (1);
		philo(av, &data);
	}
	else
	{
		printf("Wrong arguments, please try again.");
		return (2);
	}
	return (0);
}
