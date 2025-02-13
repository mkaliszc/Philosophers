/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:50:53 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/06 14:55:35 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

int	synchro_sleep(size_t sleep_time, int *dead_flag)
{
	size_t	start;

	start = get_current_time();
	while (*dead_flag != 1)
	{
		if (start >= sleep_time)
			break ;
		usleep(50);
		start = get_current_time();
	}
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!if_dead_loop(philo))
		printf("%zu --- philo %d : %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}
