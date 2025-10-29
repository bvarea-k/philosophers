/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:36:45 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/29 10:02:31 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_wrapper(t_table *table, int philo_id, const char *msg)
{
	long	timestamp;

	timestamp = ft_get_time() - table->start_time;
	pthread_mutex_lock(&table->mutex_print);
	printf("%ld %d %s\n", timestamp, philo_id, msg);
	pthread_mutex_unlock(&table->mutex_print);
}
