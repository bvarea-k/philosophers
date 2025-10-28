void	ft_eat(t_philo *philo)
{
	if (ft_is_dead(philo)) //ya hago el lock en is_dead
	{
		ft_release_forks(philo);
		return ;
	}
	printf("%ld %d is eating\n", ft_get_time() - philo->table->start_time,
		philo->id_philo);
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_lock(&philo->mutex_eat);
	philo->last_meal = ft_get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->mutex_eat);
	ft_release_forks(philo);
}

void	ft_eat(t_philo *philo)
{
	if (ft_is_dead(philo)) // ya hace el lock de mutex_dead dentro
	{
		ft_release_forks(philo);
		return ;
	}

	printf("%ld %d is eating\n",
		ft_get_time() - philo->table->start_time,
		philo->id_philo);

	// Simula el tiempo real de comer con precisión
	ft_usleep(philo->table->time_to_eat);

	// Actualiza el tiempo de la última comida AL FINAL
	pthread_mutex_lock(&philo->mutex_eat);
	philo->last_meal = ft_get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->mutex_eat);

	ft_release_forks(philo);
}
