/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:40:23 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/04 09:58:09 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_table(int ac, char **av, t_table *table)
{
	table->n_philos = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	table->must_eat = -1;
	if (ac == 6)
		table->must_eat = ft_atol(av[5]);
	table->dead = 0;
	table->start_time = 0;
	table->forks = malloc(table->n_philos * sizeof(pthread_mutex_t));
	if (!table->forks)
		return (0);
	return (1);
}

int	ft_init_philo(t_table *table)
{
	int	i;

	i = 0;
	table->philos = malloc(table->n_philos * sizeof(t_philo));
	if (!table->philos)
	{
		ft_print_error(ERROR_PHILO);
		return (0);
	}
	while (i < table-> n_philos)
	{
		table->philos[i].id_philo = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal = table->start_time;
		table->philos[i].table = table;
		i++;
	}
	return (1);
}

int	ft_init_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (0);
		i++;
	}
	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_mutex_init(&table->philos[i].mutex_eat, NULL))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&table->mutex_dead, NULL))
		return (0);
	if (pthread_mutex_init(&table->mutex_print, NULL))
		return (0);
	return (1);
}
