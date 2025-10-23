/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:23:36 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/23 10:57:22 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	table;

	table.forks = NULL;
	if (ac != 5 && ac != 6)
	{
		ft_print_error(ERROR_ARGS);
		return (1);
	}
	if (!ft_checker(av))
		return (1);
	if (!ft_init_table(ac, av, &table))
	{
		ft_free_table(&table);
		return (1);
	}
	if (!ft_init_philo(&table))
	{
		ft_free_table(&table);
		return (1);
	}
	

	//TO DO: inicializar filósofoa y crear hilos
	ft_free_table(&table);
	return (0);
}

