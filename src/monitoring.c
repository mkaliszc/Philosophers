/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:55:41 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/04 21:11:44 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_checker(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].nb_of_philos)
	{
		if (philo_dead())
		{
			// * to continue
		}
	}
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