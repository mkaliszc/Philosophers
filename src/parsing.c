/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:11:36 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/04 16:15:21 by mkaliszc         ###   ########.fr       */
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

bool	is_unsigned_int(char	*arg)
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
		if (is_unsigned_int(argv[i]) == false || check_overflows(argv[i]) == false)
			return(false);
		i++;
	}
	return (true);
}
