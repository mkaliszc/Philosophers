/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:14:19 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/03 21:07:51 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>

# define MAX_PHILO 200

typedef	struct	s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	fork;
	struct t_philo	*next;
	struct t_philo	*previous;
}					t_philo;

typedef struct s_data
{
	int	nb_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_meal;
	
}		t_data;

t_data	*init_data(int argc, char **argv);

/* lib function */

void	ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int arg);
int		ft_isspace(int c);

#endif