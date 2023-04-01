/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:04:08 by ykissiko          #+#    #+#             */
/*   Updated: 2023/04/01 13:37:12 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_params(char **argv, t_const_var *vars)
{
	vars->num = ft_int(argv[1]);
	vars->die_time = ft_int(argv[2]);
	vars->eat_time = ft_int(argv[3]);
	vars->sleep_time = ft_int(argv[4]);
	if (argv[5])
	{
		vars->max_eat = ft_int(argv[5]);
		if (vars->max_eat < 0)
			return (0);
	}
	else
		vars->max_eat = -1;
	vars->ate_num = 0;
	vars->stop = 0;
	if (vars->num > 0 && vars->die_time >= 0 && vars->sleep_time >= 0)
		return (1);
	return (0);
}

int	ft_int(char *num)
{
	int	n;
	int	i;

	i = -1;
	n = 0;
	while (num[++i])
	{
		if (num[i] >= '0' && num[i] <= '9')
		{
			n = n * 10;
			n += num[i] - 48;
		}
		else
			return (-1);
	}
	return (n);
}

void	ft_check_cond(t_const_var *vars)
{
	int	i;

	while (vars->stop == 0 && vars->ate_num != vars->num)
	{
		i = -1;
		while (++i < vars->num)
		{
			if ((get_time() - vars->philo[i].last_ate)
				> (unsigned long)vars->die_time)
			{
				vars->stop = 1;
				ft_print(vars, "died", vars->philo[i].id);
			}
			if (vars->stop == 1)
				break ;
		}
	}
}
