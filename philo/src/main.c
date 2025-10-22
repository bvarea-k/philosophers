/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:23:36 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/22 13:59:34 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	table;
	t_philo	philo;

	table.forks= NULL;
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
	if (!ft_init_philo)
	{
		//free_filo??
		return (1);
	}
	

	//TO DO: inicializar filósofoa y crear hilos
	ft_free_table(&table);
	return (0);
}

