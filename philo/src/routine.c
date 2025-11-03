/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:47:41 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/03 10:11:15 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int  ft_check_dead(t_table *table)
{
    int     i;
    long    current_time;

    i = 0;
    while (i < table->n_philos)
    {
        pthread_mutex_lock(&table->philos[i].mutex_eat);
        current_time = ft_get_time();
        if (current_time - table->philos[i].last_meal >= table->time_to_die)
        {
            pthread_mutex_unlock(&table->philos[i].mutex_eat);
			pthread_mutex_lock(&table->mutex_print);
            pthread_mutex_lock(&table->mutex_dead);
            if (!table->dead)
            {
                table->dead = 1;
                
                printf("%ld %d died\n",
                    ft_get_time() - table->start_time, table->philos[i].id_philo);
                
            }
            pthread_mutex_unlock(&table->mutex_dead);
			pthread_mutex_unlock(&table->mutex_print);
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
		usleep(50);
	}
	return (NULL);
}
static void	ft_one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->mutex_print);
	printf("%ld %d has taken a fork\n",
			ft_get_time() - philo->table->start_time, philo->id_philo);
	ft_usleep(philo->table->time_to_die);
	pthread_mutex_lock(&philo->table->mutex_dead);
	if (!philo->table->dead)
	{
		philo->table->dead = 1;
		printf("%ld %d died\n",
			ft_get_time() - philo->table->start_time, philo->id_philo);
	}
	pthread_mutex_unlock(&philo->table->mutex_dead);
	pthread_mutex_unlock(&philo->table->mutex_print);
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
	pthread_mutex_lock(&philo->mutex_eat);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->mutex_eat);
	if (philo->table->n_philos == 1)
	{
		ft_one_philo(philo);
		return (NULL);
	}
	ft_my_loop(philo);
	return (NULL);
}