/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:40:23 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/25 15:43:32 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_init_table(int ac, char **av, t_table *table)
{
	table->n_philos = ft_atol(av[1]);
	if (table->n_philos < 1)
	{
		ft_print_error(ERROR_PHILO_NUMBER);
		return (0);
	}
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		table->must_eat = ft_atol(av[5]);
	table->dead = 0;
	table->start_time = ft_get_time();
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
	while (i < table-> n_philos) // recorrer todos los filósofos
	{
		table->philos[i].id_philo = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal = table->start_time;//su última comida fue cuando iniciamos
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
		if (pthread_mutex_init(&table->philos[i].mutex_eat, NULL))// devuelve 0 si se inició bien
			return (0);
		i++;
	}
	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_mutex_init(&table->mutex_dead, NULL))// devuelve 0 si se inició bien
			return (0);
		i++;
	}
	return (1);
}

void	ft_create_thread(t_table *table)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, ft_routine, &table->philos[i])) //devuelve 0 si fue bien
			return (ft_print_error(ERROR_PHILO));
		i++;
	}
	if (pthread_create(&monitor, NULL, ft_monitor, table)) //devuelve 0 si fue bien. No puedo pasarle nada  ala función xq necesita que sea void *
			return (ft_print_error(ERROR_MONITOR));
	pthread_join(monitor, NULL); //espera a que el monitor termine (comen o alguien muere)
	i = 0;
	while (i < table->n_philos)
	{
		pthread_join(table->philos[i].thread, NULL);//el monitor espera a que los filos terminen su rutina
		i++;
	}
}
