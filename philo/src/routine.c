/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:47:41 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/01 13:28:52 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


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
		usleep(50);
	}
	return (NULL);
}
static void	ft_one_philo(t_philo *philo)
{
	if (philo->table->n_philos == 1)
	{
		printf("%ld %d has taken a fork\n",
			ft_get_time() - philo->table->start_time, philo->id_philo);
		ft_usleep(philo->table->time_to_die);
		printf("%ld %d died\n",
			ft_get_time() - philo->table->start_time, philo->id_philo);
		pthread_mutex_lock(&philo->table->mutex_dead);
		philo->table->dead = 1;
		pthread_mutex_unlock(&philo->table->mutex_dead);
	}
}
static void	ft_my_loop(t_philo *philo)
{
	while (!ft_is_dead(philo))
	{
		ft_eat(philo);
		if (ft_is_dead(philo))
			break ;
		ft_sleep(philo);
		if (ft_is_dead(philo))
			break ;
		print_wrapper(philo->table, philo->id_philo, "is thinking");
	}
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id_philo % 2 == 0)
		usleep(1000); //si es par, siesta
	philo->last_meal = ft_get_time();
	if (philo->table->n_philos == 1)
	{
		ft_one_philo(philo);
		return (NULL);
	}
	ft_my_loop(philo);
	return (NULL);
}