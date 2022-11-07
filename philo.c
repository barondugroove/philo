/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:10:58 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/07 18:56:48 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_data(t_data *data)
{
	printf("number of philosophers is %d\n", data->nbr_philo);
	printf("time to die is %dms\n", data->tt_die);
	printf("time to eat is %dms\n", data->tt_eat);
	printf("time to sleep is %dms\n", data->tt_sleep);
	if (data->max_eat_nbr)
		printf("max eat repetition is %d\n", data->max_eat_nbr);
}

void	philo(char **av, t_data *data)
{
	pthread_t	*philos;

	if (check_args_errors(av))
		return ;
	parse_data(data, av);
	print_data(data);
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
