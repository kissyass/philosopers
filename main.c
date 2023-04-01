/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:56:02 by ykissiko          #+#    #+#             */
/*   Updated: 2023/04/01 13:42:03 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_const_var	vars;

	if (argc != 5 && argc != 6)
		return (printf("Wrong number of arguments\n"));
	if (ft_check_params(argv, &vars) == 0)
		return (printf("Wrong format of the arguments\n"));
	if (ft_init_params(&vars) == 0)
		return (printf("Init failed\n"));
	if (ft_threads(&vars) == 0)
		return (printf("Threads failed\n"));
	return (0);
}
