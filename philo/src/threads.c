/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:32:42 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/03 13:57:15 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*If thread_create fails when there are already threads created,
we remove them one by one */
static int	ft_create_philo_threads(t_table *table)
{
	int	i;
	
	table->start_time = ft_get_time();
	i = 0;
	while (i < table->n_philos)
	{
		if (table->philos->id_philo % 2 != 0 && i == table->n_philos)
			ft_usleep(20);
		if (pthread_create(&table->philos[i].thread,
				NULL, ft_routine, &table->philos[i]))
		{
			ft_print_error(ERROR_PHILO);
			i--;
			while (i >= 0)
			{
				pthread_join(table->philos[i].thread, NULL);
				i--;
			}
			return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_create_monitor_thread(t_table *table, pthread_t *monitor)
{
	if (pthread_create(monitor, NULL, ft_monitor, table))
	{
		ft_print_error(ERROR_MONITOR);
		return (0);
	}
	return (1);
}

/*If the monitor creation fails, we destroy the philos*/
void	ft_create_thread(t_table *table)
{
	int			i;
	pthread_t	monitor;

	if (!ft_create_philo_threads(table))
		return ;
	if (!ft_create_monitor_thread(table, &monitor))
	{
		i = 0;
		while (i < table->n_philos)
		{
			pthread_join(table->philos[i].thread, NULL);
			i++;
		}
		return ;
	}
	pthread_join(monitor, NULL);
	i = 0;
	while (i < table->n_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}
/*Crear hilos de filos, si falla, retorno,
creo el monitor y, si falla, uno los de los filos.
Espero que termine el monitor y luego a los filos.*/
