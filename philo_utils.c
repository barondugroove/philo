/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:16:07 by bchabot           #+#    #+#             */
/*   Updated: 2022/11/07 16:49:51 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 1;
	while (n >= 10 || n <= -10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*tab;
	int				i;
	unsigned int	x;
	int				neg;

	x = n;
	neg = 0;
	if (n < 0)
	{
		x = -n;
		neg = 1;
	}
	i = ft_intlen(n);
	tab = malloc(sizeof(char) * ((i += neg) + 1));
	if (!tab)
		return (NULL);
	if (neg)
		tab[0] = '-';
	tab[i] = '\0';
	while (i-- > neg)
	{
		tab[i] = (x % 10) + '0';
		x /= 10;
	}
	return (tab);
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	neg;
	int	i;

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
	return (nbr * neg);
}
