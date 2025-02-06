/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:39:25 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/06 17:05:25 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_philo(char *str, t_data *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
		ft_putendl_fd(str, 2);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while (i < program->philos[0].nb_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
