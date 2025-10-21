/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:21:15 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/15 10:21:22 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	int	pos;
	int	s;
	int	num;

	pos = 0;
	s = 1;
	num = 0;
	while (nptr[pos] == ' ' || nptr[pos] == '\n' || nptr[pos] == '\t'
		|| nptr[pos] == '\r' || nptr[pos] == '\f' || nptr[pos] == '\v')
		pos++;
	if (nptr[pos] == '-')
	{
		s = s * -1;
		pos++;
	}
	else if (nptr[pos] == '+')
		pos++;
	while (nptr[pos] != '\0' && (nptr[pos] >= '0' && nptr[pos] <= '9'))
	{
		num = (num * 10) + (nptr[pos] - '0');
		pos++;
	}
	return (num * s);
}
