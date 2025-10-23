/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:40:23 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/23 11:38:14 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_init_table(int ac, char **av, t_table *table)
{
	int	i;

	i = 0;
	table->n_philos = atol(av[1]);
	if (table->n_philos < 1)
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
	table->start_time = ft_get_time();
	table->forks = malloc(table->n_philos * sizeof(pthread_mutex_t));
	if (!table->forks)
		return (0);
	while (i < table->n_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	return (1);
}

int	init_philo(t_table *table)
{
	int	i;

	i = 0;
	table->philos = malloc(table->n_philos * sizeof(t_philo));
	if (!table->philos)
	
}
