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


int	ft_isdigit(char *str)
{
	int i;

	i = 0;
	while(str[i])
		{
			if (c >= '0' && c <= '9')
				return (1);
		}
	return (0);
}

int	is_not_long(char *str)
{
	long	n;

	n = f_atol(str)
	if (n >= 0 && n <= 2147483647)
			return (1);
	return (0);
}

void	checker(char **av)
{
	int	i;
	
	i = 0;
	while	(av[i])
	{
		if (!ft_isdigit(av[i] || !is_not_long(av[1]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_init_table(int ac, char **av, t_table *table)
{
	table->n_philo = atol(av[1]);
	if (table->n_philo < 1)
		print_error????????????????
	table->time_to_die = atol(av[2]);
	table->time_to_eat = atol(av[3]);
	table->time_to_sleep = atol(av[4]);
	if (ac == 6)
		table->must_eat = atol(av[5]);
	table->dead = 0;
	
}

int	main(int ac, char **av)
{
	t_table	table;
	if (ac != 5 && ac != 6)
	{
		write(1, "Invalid number of arguments.\n", 29);
		return (0);
	}
	if(!checker(av));
		return 1;
	ft_init_table(ac, av, &table);
	
}
