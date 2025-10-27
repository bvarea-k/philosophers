/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:00:18 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/27 16:24:48 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
			return 0;
		}
		pthread_mutex_unlock(&table->philos[i].mutex_eat);
		i++;
	}
	return (1);
}