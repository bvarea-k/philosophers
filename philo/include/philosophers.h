/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:29:01 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/27 16:09:39 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

# define ERROR_ARGS			1
# define ERROR_NUMBER		2
# define ERROR_PHILO_NUMBER	3
# define ERROR_PHILO		4
# define ERROR_MONITOR		5

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				dead;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_dead;
	t_philo			*philos;
}	t_table;

typedef struct s_philo
{
	int				id_philo;
	long			last_meal;
	int				meals_eaten;
	pthread_t		thread;
	pthread_mutex_t	mutex_eat;
	t_table			*table;
}	t_philo;

int		ft_checker(char **av);
void	ft_print_error(int error_n);
long	ft_atol(const char *nptr);
long	ft_get_time(void);
int		ft_init_table(int ac, char **av, t_table *table);
int		ft_init_philo(t_table *table);
int		ft_init_mutex(t_table *table);
void	ft_free_table(t_table *table);
void	ft_create_thread(t_table *table);
void	*ft_routine(void *arg);
void	*ft_monitor(void *arg);
void	ft_take_forks(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
int		ft_all_ate(t_table *table);

#endif
