/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:32:00 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/24 16:57:30 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_are_alive(t_table *table)
{
	int		i;
	long	current_time;

	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_lock(&table->philos[i].mutex_eat);
		current_time = ft_get_time(); //me da el tiempo en milis desde que empezamos
		if (current_time - table->philos[i].last_meal >= table->time_to_die) // si el tiempo desd que comió es mayor o igual al necesario para morir
		{
			table->dead = 1;
			pthread_mutex_unlock(&table->philos[i].mutex_eat);
			printf("%ld %d is dead\n", current_time - table->start_time,
					table->philos[i].id_philo);
			return (0); // ya no están vivos
		}
		pthread_mutex_unlock(&table->philos[i].mutex_eat);
		i++;
	}
	if (table->dead)
		return (0);
	return (1);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->time_to_die == 0) //si el tiempo para morir es 0, paro.
		return (NULL);
	while (ft_are_alive(philo->table)) //TO DO: llamarla con el hilo monitor
	{
		//piensa
		//coge el tenedor
		//come
		//suelta el tenedor
		//duerme
	}
	//return (NULL); probar cuando pueda probar el programa
}