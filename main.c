/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:10:58 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/09 20:16:03 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(char **av, t_data *data)
{
	t_philo		*philos;
	pthread_t	*philos_id;
	int			i;

	i = 0;
	if (check_args_errors(av))
		return ;
	parse_data(data, av);
	philos = malloc(sizeof(t_philo) * data->nbr_philo);
	philos_id = malloc(sizeof(pthread_t) * data->nbr_philo);
	init_data(philos, data);
	print_data(data, philos);
	while (i < data->nbr_philo)
	{
		pthread_create(&philos_id[i], NULL, &life, &philos[i]);
		usleep(50);
		i++;
	}
	//death(philos);
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_join(philos_id[i], NULL);
		i++;
	}
	return ;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac > 4 && ac <= 6)
		philo(av, &data);
	else
		ft_putendl_fd("Wrong arguments, please try again.", 2);
	return (0);
}
