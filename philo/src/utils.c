/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:26:46 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/01 13:51:47 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_is_dead(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&philo->table->mutex_dead);
	dead = philo->table->dead;
	pthread_mutex_unlock(&philo->table->mutex_dead);
	return (dead);
}

int	ft_all_ate(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_lock(&table->philos[i].mutex_eat);
		if (table->philos[i].meals_eaten < table->must_eat)
		{
			pthread_mutex_unlock(&table->philos[i].mutex_eat);
			return (0);
		}
		pthread_mutex_unlock(&table->philos[i].mutex_eat);
		i++;
	}
	return (1);
}