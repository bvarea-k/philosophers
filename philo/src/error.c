/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:31:49 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/22 11:51:02 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_error(int error_n)
{
	if (error_n == ERROR_ARGS)
		prinft("Invalid number of arguments.\n");
	else if (error_n == ERROR_NUMBER)
		prinft("All arguments must be numbers between 1 and 200.\n");
	else if (error_n == ERROR_PHILO_NUMBER)
		prinft("There must be at least 1 philosopher.\n");
	
}