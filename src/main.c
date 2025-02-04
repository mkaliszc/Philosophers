/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:32:51 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/04 03:49:05 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// * get ft_atoi from libft

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 6 && argc != 5)
		return(ft_putstr_fd("the numbers of arg must be 5 or 6\n", 2), 1);
	data = init_data(argc, argv);
	if (!data)
		return(1);
	create_philosophers(data);
}