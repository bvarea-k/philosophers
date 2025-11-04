/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:35:59 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/04 09:51:00 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_take_forks(t_philo *philo)
{
	int	l_fork;
	int	r_fork;

	l_fork = philo->id_philo - 1;
	r_fork = (philo->id_philo) % philo->table->n_philos;
	if (philo->id_philo % 2 != 0)
		return (ft_take_odd_forks(philo, l_fork, r_fork));
	else
		return (ft_take_even_forks(philo, l_fork, r_fork));
}

static void	ft_release_forks(t_philo *philo)
{
	int	l_fork;
	int	r_fork;

	l_fork = philo->id_philo - 1;
	r_fork = (philo->id_philo) % philo->table->n_philos;
	pthread_mutex_unlock(&philo->table->forks[l_fork]);
	pthread_mutex_unlock(&philo->table->forks[r_fork]);
}

void	ft_eat(t_philo *philo)
{
	if (!ft_take_forks(philo))
		return ;
	if (ft_is_dead(philo))
	{
		ft_release_forks(philo);
		return ;
	}
	if (pthread_mutex_lock(&philo->mutex_eat))
	{
		ft_release_forks(philo);
		return ;
	}
	philo->last_meal = ft_get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->mutex_eat);
	print_wrapper(philo->table, philo->id_philo, "is eating");
	ft_usleep(philo->table->time_to_eat);
	ft_release_forks(philo);
}

void	ft_sleep(t_philo *philo)
{
	long	end_time;

	end_time = ft_get_time() + philo->table->time_to_sleep;
	print_wrapper(philo->table, philo->id_philo, "is sleeping");
	while (ft_get_time() < end_time)
	{
		pthread_mutex_lock(&philo->table->mutex_dead);
		if (philo->table->dead)
		{
			pthread_mutex_unlock(&philo->table->mutex_dead);
			return ;
		}
		pthread_mutex_unlock(&philo->table->mutex_dead);
		usleep(100);
	}
}
