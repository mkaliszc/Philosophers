/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:55:41 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/04 23:50:08 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

// Checks if the philosopher is dead

int	philosopher_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

bool	meal_checker(t_philo *philo)
{
	int		i;
	int		finished_eating;

	i = 0;
	finished_eating = 0;
	if (philo[0].total_nb_of_meals)
		return (false);
	while (i < philo[0].nb_of_philos)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten >= philo[i].total_nb_of_meals)
			finished_eating++;;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (finished_eating == philo[0].nb_of_philos)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		philo->is_dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (1);
	}
	return (0);
}

int	dead_checker(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].nb_of_philos)
	{
		if (philo_dead())
		{
			write_msg("is dead", philos[i], philos[i].id);
			pthread_mutex_lock(philos[0].dead_lock);
			philos->is_dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return(1);
		}
		i++;
	}
	return (0);
}

void	*monitor(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	while (true)
		if (dead_checker(philos) == 1 || meal_checker(philos) == 1)
			break ;
	return (ptr);
}