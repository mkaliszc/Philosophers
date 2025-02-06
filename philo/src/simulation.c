/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:47:16 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/06 14:56:25 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	if_dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->is_dead)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*routine(void *ptr)
{
	t_philo	*cur_philo;

	cur_philo = (t_philo *)ptr;
	if (cur_philo->id % 2 == 0)
		usleep(15000);
	while (if_dead_loop(cur_philo) != 1)
	{
		eat(cur_philo);
		go_to_bed(cur_philo);
		think(cur_philo);
	}
	return (ptr);
}

int	thread_create(t_data *data, pthread_mutex_t *forks)
{
	pthread_t	checker;
	int			i;

	if (pthread_create(&checker, NULL, &monitor, data->philos) != 0)
		cleanup_philo("Error while creating checker thread", data, forks);
	i = 0;
	while (i < data->philos[0].nb_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				&routine, &data->philos[i]) != 0)
			cleanup_philo("Error while creating a thread", data, forks);
		i++;
	}
	i = 0;
	if (pthread_join(checker, NULL) != 0)
		cleanup_philo("Error while joining checker", data, forks);
	while (i < data->philos[0].nb_of_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			cleanup_philo("Error while joining a philo", data, forks);
		i++;
	}
	return (0);
}
