/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:53:12 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/29 11:56:44 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_is_dead(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&philo->table->mutex_dead);
	dead = philo->table->dead;
	pthread_mutex_unlock(&philo->table->mutex_dead);
	return (dead);
}

void	ft_take_forks(t_philo *philo)
{
	if (philo->id_philo % 2 != 0)
	{
		////if (ft_is_dead(philo))
			return ;
		pthread_mutex_lock(&philo->table->forks[philo->id_philo - 1]);
		if (ft_is_dead(philo))
		{
			pthread_mutex_unlock(&philo->table->forks[philo->id_philo - 1]);
			return ;
		}
		print_wrapper(philo->table, philo->id_philo, "has taken l fork");
		pthread_mutex_lock(&philo->table->forks[philo->id_philo
			% philo->table->n_philos]);
		if (ft_is_dead(philo))
		{
			pthread_mutex_unlock(&philo->table->forks[philo->id_philo - 1]);
			pthread_mutex_unlock(&philo->table->forks[philo->id_philo
				% philo->table->n_philos]);
			return ;
		}
		print_wrapper(philo->table, philo->id_philo, "has taken r fork");
	}
	else
	{
		if (ft_is_dead(philo))
			return ;
		pthread_mutex_lock(&philo->table->forks[philo->id_philo
			% philo->table->n_philos]);
		if (ft_is_dead(philo))
		{
			pthread_mutex_unlock(&philo->table->forks[philo->id_philo
				% philo->table->n_philos]);
			return ;
		}
		print_wrapper(philo->table, philo->id_philo, "has taken r fork");
		pthread_mutex_lock(&philo->table->forks[philo->id_philo - 1]);
		if (ft_is_dead(philo))
		{
			pthread_mutex_unlock(&philo->table->forks[philo->id_philo - 1]);
			pthread_mutex_unlock(&philo->table->forks[philo->id_philo
				% philo->table->n_philos]);
			return ;
		}
		print_wrapper(philo->table, philo->id_philo, "has taken l fork");
	}
}

static void	ft_release_forks(t_philo *philo)
{
	int	next_fork;

	next_fork = philo->id_philo % philo->table->n_philos;
	if (philo->id_philo % 2 != 0)
	{
		pthread_mutex_unlock(&philo->table->forks[philo->id_philo - 1]);
		pthread_mutex_unlock(&philo->table->forks[next_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->forks[next_fork]);
		pthread_mutex_unlock(&philo->table->forks[philo->id_philo - 1]);
	}
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_eat);
	if (ft_is_dead(philo))
	{
		ft_release_forks(philo);
		return ;
	}
	print_wrapper(philo->table, philo->id_philo, "is eating");
	philo->last_meal = ft_get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->mutex_eat);
	usleep(philo->table->time_to_eat * 1000);
	ft_release_forks(philo);
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->mutex_dead);
	if (philo->table->dead)
	{
		pthread_mutex_unlock(&philo->table->mutex_dead);
		return ;
	}
	pthread_mutex_unlock(&philo->table->mutex_dead);
	print_wrapper(philo->table, philo->id_philo, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
	pthread_mutex_lock(&philo->table->mutex_dead);
	if (philo->table->dead)
	{
		pthread_mutex_unlock(&philo->table->mutex_dead);
		return ;
	}
	pthread_mutex_unlock(&philo->table->mutex_dead);
}
