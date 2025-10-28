void	ft_take_forks(t_philo *philo)
{
	int	right = philo->id_philo % philo->table->n_philos;
	int	left = philo->id_philo - 1;

	if (philo->id_philo % 2 != 0)
	{
		if (ft_is_dead(philo))
			return ;
		pthread_mutex_lock(&philo->table->forks[left]);
		if (ft_is_dead(philo))
		{
			pthread_mutex_unlock(&philo->table->forks[left]);
			return ;
		}
		printf("%ld %d has taken the left fork\n",
			ft_get_time() - philo->table->start_time, philo->id_philo);

		pthread_mutex_lock(&philo->table->forks[right]);
		if (ft_is_dead(philo))
		{
			pthread_mutex_unlock(&philo->table->forks[left]);
			pthread_mutex_unlock(&philo->table->forks[right]);
			return ;
		}
		printf("%ld %d has taken the right fork\n",
			ft_get_time() - philo->table->start_time, philo->id_philo);
	}
	else
	{
		if (ft_is_dead(philo))
			return ;
		pthread_mutex_lock(&philo->table->forks[right]);
		if (ft_is_dead(philo))
		{
			pthread_mutex_unlock(&philo->table->forks[right]);
			return ;
		}
		printf("%ld %d has taken the right fork\n",
			ft_get_time() - philo->table->start_time, philo->id_philo);

		pthread_mutex_lock(&philo->table->forks[left]);
		if (ft_is_dead(philo))
		{
			pthread_mutex_unlock(&philo->table->forks[right]);
			pthread_mutex_unlock(&philo->table->forks[left]);
			return ;
		}
		printf("%ld %d has taken the left fork\n",
			ft_get_time() - philo->table->start_time, philo->id_philo);
	}
}
