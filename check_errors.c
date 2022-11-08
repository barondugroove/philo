/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:32:52 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/08 18:55:37 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	check_args_errors(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_isnumber(av[i]))
		{
			printf("Arguments n°%d is not a number please try again.\n", i);
			return (i);
		}
		if (i == 1 && ft_atoi(av[i]) == 0)
		{
			printf("Number of philosophers is zero.\n");
			return (i);
		}
		i++;
	}
	return (0);
}
