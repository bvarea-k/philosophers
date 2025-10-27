/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:32:00 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/27 16:08:54 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_check_dead(t_table *table)
{
	int		i;
	long	current_time;

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
			return (1);
		}
		pthread_mutex_unlock(&table->philos[i].mutex_eat);
		i++;
	}
	return (0);
}

void	*ft_monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		if (table->must_eat > 0 && ft_all_ate(table))
		{
			pthread_mutex_lock(&table->mutex_dead);
			table->dead = 1;
			pthread_mutex_unlock(&table->mutex_dead);
			break ;
		}
		if (ft_check_dead(table))
			break ;
		pthread_mutex_lock(&table->mutex_dead);
		if (table->dead)
		{
			pthread_mutex_unlock(&table->mutex_dead);
			break ;
		}
		pthread_mutex_unlock(&table->mutex_dead);
		usleep(100);
	}
	return (NULL);
}

static void	ft_one_philo(t_philo *philo)
{
	if (philo->table->n_philos == 1)
	{
		printf("%ld %d has taken the left fork\n",
			ft_get_time() - philo->table->start_time, philo->id_philo);
		usleep(philo->table->time_to_die);
		printf("%ld %d died\n",
			ft_get_time() - philo->table->start_time, philo->id_philo);
		pthread_mutex_lock(&philo->table->mutex_dead);
		philo->table->dead = 1;
		pthread_mutex_unlock(&philo->table->mutex_dead);
	}
}

static void	ft_my_loop(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->table->mutex_dead);
		if (philo->table->dead)
		{
			pthread_mutex_unlock(&philo->table->mutex_dead);
			break ;
		}
		pthread_mutex_unlock(&philo->table->mutex_dead);
		ft_take_forks(philo);
		ft_eat(philo);
		if (philo->table->dead)
			break ;
		ft_sleep(philo);
		if (philo->table->dead)
			break ;
		printf("%ld %d is thinking\n",
			ft_get_time() - philo->table->start_time, philo->id_philo);
	}
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = ft_get_time();
	if (philo->table->n_philos == 1)
	{
		ft_one_philo(philo);
		return (NULL);
	}
	ft_my_loop(philo);
	return (NULL);
}
