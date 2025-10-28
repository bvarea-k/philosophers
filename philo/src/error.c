/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:31:49 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/28 11:02:55 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_error(int error_n)
{
	if (error_n == ERROR_ARGS)
		printf("Invalid number of arguments.\n");
	else if (error_n == ERROR_PHILO_NUMBER)
		printf("There must be between 1 and 200 philosophers.\n");
	else if (error_n == ERROR_NUMBER)
		printf("All arguments must be numbers between 1 and 2147483647.\n");
	else if (error_n == ERROR_PHILO)
		printf("Error creating philosopher.\n");
	else if (error_n == ERROR_MONITOR)
		printf("Error creating monitor thread.\n");
}
