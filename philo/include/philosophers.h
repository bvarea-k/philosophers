/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:29:01 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/10/25 16:27:02 by bvarea-k         ###   ########.fr       */
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
	int				n_philos; //número de filósofos. Define el tamaño
	int				time_to_die; //tiempo que puede pasar sin comer
	int				time_to_eat; //tiempo que tarda en comer
	int				time_to_sleep; //tiempo que tarda en dormir
	int				must_eat; //número opcional de veces que comer
	int				dead; //flag de muerto
	int				start_time; //tiempo del inicio de la sesión
	pthread_mutex_t	*forks; //array de mutexes de tenedores
	pthread_mutex_t	mutex_dead; //proteger acceso a dead
	t_philo			*philos;
}	t_table;

typedef struct s_philo
{
	int				id_philo; // identificador del folósofo
	long			last_meal;//cuando el philo empezó a comer por última vez
	int				meals_eaten;//cuántas veces ha comido
	pthread_t		thread; //Los hilos
	pthread_mutex_t	mutex_eat;//proteger acceso a last_meal y meals_eaten, evitar condiciones de carrera
	t_table			*table; //puntero a estructura general
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

#endif
