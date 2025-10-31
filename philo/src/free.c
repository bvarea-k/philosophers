/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:04:05 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/31 16:25:55 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_free_forks(t_table *table)
{
	int	i;

	if (!table->forks)
		return ;
	i = 0;
	if (table->forks)
	{
		while (i < table->n_philos)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
	}
}

void	ft_free_table(t_table *table)
{
	int	i;

	if (!table)
		return ;
	pthread_mutex_destroy(&table->mutex_print);
	pthread_mutex_destroy(&table->mutex_dead);
	ft_free_forks(table);
	i = 0;
	if (table->philos)
	{
		while (i < table->n_philos)
		{
			pthread_mutex_destroy(&table->philos[i].mutex_eat);
			i++;
		}
		free(table->philos);
	}
}
	
