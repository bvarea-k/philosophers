/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:26:46 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/04 10:13:23 by bvarea-k         ###   ########.fr       */
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

int	ft_take_odd_forks(t_philo *philo, int l_fork, int r_fork)
{
	if (ft_is_dead(philo))
		return (0);
	if (pthread_mutex_lock(&philo->table->forks[l_fork]))
		return (0);
	print_wrapper(philo->table, philo->id_philo, "has taken l fork");
	if (ft_is_dead(philo))
	{
		pthread_mutex_unlock(&philo->table->forks[l_fork]);
		return (0);
	}
	if (pthread_mutex_lock(&philo->table->forks[r_fork]))
	{
		pthread_mutex_unlock(&philo->table->forks[l_fork]);
		return (0);
	}
	print_wrapper(philo->table, philo->id_philo, "has taken r fork");
	return (1);
}

int	ft_take_even_forks(t_philo *philo, int l_fork, int r_fork)
{
	if (ft_is_dead(philo))
		return (0);
	if (pthread_mutex_lock(&philo->table->forks[r_fork]))
		return (0);
	print_wrapper(philo->table, philo->id_philo, "has taken r fork");
	if (ft_is_dead(philo))
	{
		pthread_mutex_unlock(&philo->table->forks[r_fork]);
		return (0);
	}
	if (pthread_mutex_lock(&philo->table->forks[l_fork]))
	{
		pthread_mutex_unlock(&philo->table->forks[r_fork]);
		return (0);
	}
	print_wrapper(philo->table, philo->id_philo, "has taken l fork");
	return (1);
}

void	ft_announce_death(t_table *table, int i)
{
	table->dead = 1;
	printf("%ld %d died\n", ft_get_time() - table->start_time,
		table->philos[i].id_philo);
}
