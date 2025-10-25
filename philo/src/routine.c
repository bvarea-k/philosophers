/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:32:00 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/25 16:26:38 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*int	ft_are_alive(t_table *table)
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
			table->dead = 1; //se muere
			pthread_mutex_unlock(&table->philos[i].mutex_eat); //desbloqueo
			printf("%ld %d is dead\n", current_time - table->start_time,
					table->philos[i].id_philo); //informo a los familiares del fallecimiento
			return (0);
		}
		pthread_mutex_unlock(&table->philos[i].mutex_eat); //desbloqueo igual si están vivos
		i++;
	}
	if (table->dead)
		return (0);
	return (1);
}*/
void	*ft_monitor(void *arg)
{
	t_table	*table;
	int		i;
	long	current_time;

	table = (t_table *)arg;
	while (1)
	{
		i = 0;
		while (i < table->n_philos)
		{
			pthread_mutex_lock(&table->philos[i].mutex_eat);
			current_time = ft_get_time();
			if (current_time - table->philos[i].last_meal >= table->time_to_die)
			{
				pthread_mutex_unlock(&table->philos[i].mutex_eat);
				pthread_mutex_lock(&table->mutex_dead);
				table->dead = 1;
				pthread_mutex_unlock(&table->mutex_dead);
				printf("%ld %d died\n", current_time - table->start_time,
					table->philos[i].id_philo);
				return (NULL);
			}
			pthread_mutex_unlock(&table->philos[i].mutex_eat);
			i++;
		}
		pthread_mutex_lock(&table->mutex_dead);
		if (table->dead)
		{
			pthread_mutex_unlock(&table->mutex_dead);
			break;
		}
		pthread_mutex_unlock(&table->mutex_dead);
		usleep(1000);
	}
	return (NULL);
}


void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->time_to_die == 0) //si el tiempo para morir es 0, paro.
		return (NULL);
	while (1)
	{
		pthread_mutex_lock(&philo->table->mutex_dead);
		if (philo->table->dead)
		{
			pthread_mutex_unlock(&philo->table->mutex_dead);
			break;
		}
		pthread_mutex_unlock(&philo->table->mutex_dead);
		ft_take_forks(philo);
		//come
		//suelta el tenedor
		//duerme
	}
	return (NULL); //probar cuando pueda probar el programa
}