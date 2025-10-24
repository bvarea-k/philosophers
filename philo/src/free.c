/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:04:05 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/24 16:56:24 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free_table(t_table *table)
{
	int	i;

	if (!table)
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
