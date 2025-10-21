/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:23:36 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/15 10:23:38 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (2048);
	}
	else
	{
		return (0);
	}
}

void	checker(char **av)
{
	int	i;
	
	i = 0;
	while	(*av[i])
	{
		if (*av[i] < '0' || av[i] > '9')
			return (0);
		if (*av[i] < -2147483648 || *av[i] > 2.147.483.647)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		write(1, "Invalid number of arguments.\n", 29);
		return (0);
	}
	checker(av);
}
