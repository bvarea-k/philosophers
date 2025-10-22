/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:19:15 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/22 13:35:26 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isdigit(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
		return (0);
	while(str[i])
		{
			if (str[i] >= '0' && str[i] <= '9')
				return (1);
		}
	return (0);
}

static int	is_not_long(char *str)
{
	long	n;

	n = ft_atol(str);
	if (n >= 0 && n <= 2147483647)
			return (1);
	return (0);
}

int	ft_checker(char **av)
{
	int	i;

	i = 1;
	while	(av[i])
	{
		if (!ft_isdigit(av[i]))
			ft_print_error(ERROR_NUMBER);
		else if (!is_not_long(av[i]))
			ft_print_error(ERROR_NUMBER);
		i++;
	}
	return (1);
}