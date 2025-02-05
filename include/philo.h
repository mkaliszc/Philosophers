/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:14:19 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/05 16:23:55 by mkaliszc         ###   ########.fr       */
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
# include <sys/time.h>

# define MAX_PHILO 200

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				nb_of_philos;
	int				total_nb_of_meals;
	int				is_dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_data
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_data;

t_data	*init_data(int argc, char **argv);
void	init_forks_mutex(pthread_mutex_t *forks, int philo_num);
void	init_philo(t_philo *philos, t_data *data, pthread_mutex_t *fork, char **argv);
bool	check_args_format(int argc, char **argv);
int		thread_create(t_data *data, pthread_mutex_t *forks);

void	*monitor(void *ptr);
void	print_message(char *str, t_philo *philo, int id);
size_t	get_current_time(void);
void	cleanup_philo(char *str, t_data *program, pthread_mutex_t *forks);

int		if_dead_loop(t_philo *philo);
int		ft_usleep(size_t milliseconds);
void	go_to_bed(t_philo *philo);
void	think(t_philo *philo);
void	eat(t_philo *philo);

/* lib function */

void	ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int arg);
int		ft_isspace(int c);
int		ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);

#endif