/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:11:18 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/04 23:40:57 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_time(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->nb_of_philos = ft_atoi(argv[1]);
	if (argv[5])
		philo->total_nb_of_meals = ft_atoi(argv[5]);
	else
		philo->total_nb_of_meals = -1;
}

void	init_philo(t_philo *philos, t_data *data, pthread_mutex_t *fork, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_time(&philos[i], argv);
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].write_lock = &data->write_lock;
		philos[i].dead_lock = &data->dead_lock;
		philos[i].meal_lock = &data->meal_lock;
		philos[i].is_dead = data->dead_flag;
		philos[i].l_fork = &fork[i];
		if ( i == 0)
			philos[i].r_fork = &fork[philos[i].nb_of_philos - 1];
		else
			philos[i].r_fork = &fork[i - 1];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
		pthread_mutex_init(&forks[i], NULL);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*return_ptr;

	if (check_args_format(argc, argv) == false)
		return(NULL);
	return_ptr = malloc(sizeof(t_data));
	if (!return_ptr)
		return(ft_putstr_fd("Error : malloc t_data", 2), NULL);
	pthread_mutex_init(&return_ptr->dead_lock, NULL);
	pthread_mutex_init(&return_ptr->meal_lock, NULL);
	pthread_mutex_init(&return_ptr->write_lock, NULL);
	return_ptr->dead_flag = 0;
	return (return_ptr);
}