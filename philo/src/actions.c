/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:35:59 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/02 15:55:49 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_take_forks(t_philo *philo)
{
	int	l_fork;
	int	r_fork;

	l_fork = philo->id_philo - 1;
	r_fork = (philo->id_philo) % philo->table->n_philos;
	if (philo->id_philo % 2 != 0)
	{
		if (ft_is_dead(philo))
			return ;
		if (pthread_mutex_lock(&philo->table->forks[l_fork]))
			return ;		
		print_wrapper(philo->table, philo->id_philo, "has taken l fork");		
		if (ft_is_dead(philo))
		{
			pthread_mutex_unlock(&philo->table->forks[l_fork]);
			return ;
		}
		if (pthread_mutex_lock(&philo->table->forks[r_fork]))
			return ;
		print_wrapper(philo->table, philo->id_philo, "has taken r fork");
	}
	else
	{
		if (ft_is_dead(philo))
			return ;
		if (pthread_mutex_lock(&philo->table->forks[r_fork]))
			return ;
		print_wrapper(philo->table, philo->id_philo, "has taken r fork");
		
		if (ft_is_dead(philo))
		{
			pthread_mutex_unlock(&philo->table->forks[r_fork]);
			return ;
		}
		if (pthread_mutex_lock(&philo->table->forks[l_fork]))
			return ;
		print_wrapper(philo->table, philo->id_philo, "has taken l fork");
	}
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
	ft_take_forks(philo);
	if (ft_is_dead(philo))
	{
		ft_release_forks(philo);
		return ;
	}
	if (pthread_mutex_lock(&philo->mutex_eat))
		return ;
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