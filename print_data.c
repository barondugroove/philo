/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:48:22 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/10 19:18:46 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *msg)
{
	t_philo	*p;

	p = philo;
	pthread_mutex_lock(&p->data->print);
	printf("%d %d %s\n", (get_time() - p->data->time), p->my_id, msg);
	pthread_mutex_unlock(&p->data->print);
	return ;
}

void	print_data(t_data *data, int i)
{
	printf("I am philosopher %d\n", i);
	printf("number of philosophers is %d\n", data->nbr_philo);
	printf("time to die is %dms\n", data->tt_die);
	printf("time to eat is %dms\n", data->tt_eat);
	printf("time to sleep is %dms\n", data->tt_sleep);
	if (data->max_eat_nbr)
		printf("max eat repetition is %d\n", data->max_eat_nbr);
	printf("------------------------------------\n\n");
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
