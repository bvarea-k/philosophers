/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:19:15 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/28 11:02:43 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	is_not_long_neg(char *str)
{
	long	n;

	n = ft_atol(str);
	if (n >= 1 && n <= 2147483647)
		return (1);
	return (0);
}

int	ft_checker(char **av)
{
	int	i;

	i = 1;
	if (atol(av[1]) > 200)
	{
		ft_print_error(ERROR_PHILO_NUMBER);
		return (0);
	}
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
		{
			ft_print_error(ERROR_NUMBER);
			return (0);
		}
		else if (!is_not_long_neg(av[i]))
		{
			ft_print_error(ERROR_NUMBER);
			return (0);
		}
		i++;
	}
	return (1);
}
