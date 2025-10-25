/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:53:12 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/25 17:01:23 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// coger tenedor, comer, soltar tenedor, dormir, pensar??????

/*void	take_forks(t_philo *philo) impares hacen todo y los pares espperan
{
	if (philo->id_philo % 2 != 0) //si es impar
	{
		pthread_mutex_lock(&philo->table->forks[philo->id_philo - 1]);
		printf("%ld %d has taken the left fork\n", ft_get_time() - philo->table->start_time, philo->id_philo);
		pthread_mutex_lock(&philo->table->forks[philo->id_philo % philo->table->n_philos]);
		printf("%ld %d has taken the right fork\n", ft_get_time() - philo->table->start_time, philo->id_philo);
	}
	else
	usleep(1000);
}*/

/*void	take_forks(t_philo *philo)
{
	if (philo->id_philo % 2 == 0)
		usleep(1000); // los pares esperan
	pthread_mutex_lock(&philo->table->forks[philo->id_philo - 1]);
	printf("%ld %d has taken left fork\n", ft_get_time() - philo->table->start_time, philo->id_philo);
	pthread_mutex_lock(&philo->table->forks[philo->id_philo % philo->table->n_philos]);
	printf("%ld %d has taken right fork\n", ft_get_time() - philo->table->start_time, philo->id_philo);
}*/


void	ft_take_forks(t_philo *philo)
{
	if (philo->id_philo % 2 != 0) // impares cogen primero el izquiero
	{
		pthread_mutex_lock(&philo->table->forks[philo->id_philo - 1]);
		printf("%ld %d has taken the left fork\n",
				ft_get_time() - philo->table->start_time, philo->id_philo);
		pthread_mutex_lock(&philo->table->forks[philo->id_philo % philo->table->n_philos]);
		printf("%ld %d has taken the right fork\n",
				ft_get_time() - philo->table->start_time, philo->id_philo);
	}
	else // pares cogen primero el derecho
	{
		pthread_mutex_lock(&philo->table->forks[philo->id_philo % philo->table->n_philos]);
		printf("%ld %d has taken the right fork\n",
				ft_get_time() - philo->table->start_time, philo->id_philo);
		pthread_mutex_lock(&philo->table->forks[philo->id_philo - 1]);
		printf("%ld %d has taken the left fork\n",
				ft_get_time() - philo->table->start_time, philo->id_philo);
	}
}

void ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_eat);
	philo->last_meal = ft_get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->mutex_eat);

	printf("%ld %d is eating\n", ft_get_time() - philo->table->start_time,
			philo->id_philo);
	usleep(philo->table->time_to_eat * 1000);
// liberar tenedores en el mismo orden que se cogieron
	if (philo->id_philo % 2 != 0)
	{
		pthread_mutex_unlock(&philo->table->forks[philo->id_philo - 1]);
		pthread_mutex_unlock(&philo->table->forks[philo->id_philo
								% philo->table->n_philos]);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->forks[philo->id_philo
								% philo->table->n_philos]);
		pthread_mutex_unlock(&philo->table->forks[philo->id_philo - 1]);
	}
}

