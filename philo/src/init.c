/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:40:23 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/22 13:34:13 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_table(int ac, char **av, t_table *table)
{
	int	i;

	i = 0;
	table->n_philo = atol(av[1]);
	if (table->n_philo < 1)
	{
		ft_print_error(ERROR_PHILO_NUMBER);
		return (0);
	}
	table->time_to_die = atol(av[2]);
	table->time_to_eat = atol(av[3]);
	table->time_to_sleep = atol(av[4]);
	if (ac == 6)
		table->must_eat = atol(av[5]);
	table->dead = 0;
	table->forks = malloc(table->n_philo * sizeof(pthread_mutex_t));
	if (!table->forks)
		return (0);
	while (i < table->n_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	return (1);
}

//int	init_philo(