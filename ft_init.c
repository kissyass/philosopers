/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:02:47 by ykissiko          #+#    #+#             */
/*   Updated: 2023/04/01 13:38:02 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_mutex(t_const_var *vars)
{
	int	i;

	i = -1;
	while (++i < vars->num)
	{
		if (pthread_mutex_init(&(vars->fork[i]), NULL))
			return (0);
	}
	if (pthread_mutex_init(&vars->print, NULL))
		return (0);
	return (1);
}

int	ft_init_philo(t_const_var *vars)
{
	int	i;

	i = -1;
	while (++i < vars->num)
	{
		vars->philo[i].id = i + 1;
		vars->philo[i].ate = 0;
		vars->philo[i].fork = vars->fork;
		vars->philo[i].var = vars;
	}
	return (1);
}

int	ft_init_params(t_const_var *vars)
{
	vars->philo = malloc(sizeof(t_philo) * vars->num);
	if (!vars->philo)
		return (0);
	vars->fork = malloc(sizeof(pthread_mutex_t) * vars->num);
	if (!vars->fork)
	{
		free(vars->philo);
		return (0);
	}
	if (ft_init_mutex(vars) == 0 || ft_init_philo(vars) == 0)
	{
		free(vars->philo);
		free(vars->fork);
		return (0);
	}
	return (1);
}
