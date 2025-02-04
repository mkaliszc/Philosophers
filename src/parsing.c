/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:11:36 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/04 03:48:06 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_overflows(char *arg)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(arg[i]))
		i++;
	while (arg[i] != '\0')
	{
		nbr = (nbr * 10) + (arg[i] - '0');
		if (nbr > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

bool	is_int(char	*arg)
{
	int	j;

	j = 0;
	if (!arg[j])
		return (ft_putstr_fd("invalid arg format\n", 2),false);
	while (arg[j] != '\0')
	{
		if (ft_isdigit(arg[j]) == 0)
			return (ft_putstr_fd("arg must be a positive int\n", 2), false);
		j++;
	}
	return (true);
}

bool	check_args_format(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (is_int(argv[i]) == false || check_overflows(argv[i]) == false)
			return(false);
		i++;
	}
	return (true);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*return_ptr;

	if (check_args_format(argc, argv) == false)
		return(NULL);
	return_ptr = malloc(sizeof(t_data));
	if (!return_ptr)
		return(ft_putstr_fd("Error : malloc t_data", 2), NULL);
	return_ptr->nb_of_philo = ft_atoi(argv[1]);
	if (return_ptr->nb_of_philo == 0 || return_ptr->nb_of_philo > MAX_PHILO)
		return(ft_putstr_fd("Too much  philosophers\n", 2), free(return_ptr), NULL);
	return_ptr->time_to_die = ft_atoi(argv[2]);
	return_ptr->time_to_eat = ft_atoi(argv[3]);
	return_ptr->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		return_ptr->nb_meal = ft_atoi(argv[5]);
	else
		return_ptr->nb_meal = -1;
	return(return_ptr);
}
