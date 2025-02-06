/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:32:51 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/06 17:05:42 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data			*data;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	if (argc != 6 && argc != 5)
		return (ft_putstr_fd("the numbers of arg must be 5 or 6\n", 2), 1);
	data = init_data(argc, argv);
	if (!data)
		return (1);
	philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	data->philos = philos;
	init_forks_mutex(forks, ft_atoi(argv[1]));
	init_philo(philos, data, forks, argv);
	thread_create(data, forks);
	cleanup_philo(NULL, data, forks);
	free(data->philos);
	free(forks);
	free(data);
}
