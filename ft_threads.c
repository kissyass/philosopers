/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:40:29 by ykissiko          #+#    #+#             */
/*   Updated: 2023/04/01 13:40:09 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *p)
{
	t_philo		*philo;
	t_const_var	*vars;

	philo = (t_philo *)p;
	vars = philo->var;
	if (philo->id % 2 == 0)
		ft_sleep(vars->eat_time / 10, vars);
	while (vars->stop == 0)
	{
		ft_eat(philo, vars);
		ft_print(vars, "is sleeping", philo->id);
		ft_sleep(vars->sleep_time, vars);
		ft_print(vars, "is thinking", philo->id);
	}
	return (NULL);
}

void	ft_sleep(unsigned long time, t_const_var *vars)
{
	unsigned long	start;

	start = get_time();
	while (!vars->stop)
	{
		if (get_time() - start >= time)
			break ;
		usleep(time / 10);
	}
}

void	ft_eat(t_philo *philo, t_const_var *vars)
{
	pthread_mutex_lock(&philo->fork[philo->id - 1]);
	ft_print(vars, "has taken a fork", philo->id);
	pthread_mutex_lock(&philo->fork[philo->id % vars->num]);
	ft_print(vars, "has taken a fork", philo->id);
	ft_print(vars, "is eating", philo->id);
	philo->last_ate = get_time();
	philo->ate++;
	if (philo->ate == vars->max_eat)
		vars->ate_num++;
	ft_sleep(vars->eat_time, vars);
	pthread_mutex_unlock(&philo->fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->fork[philo->id % vars->num]);
}

void	ft_exit(t_const_var *vars)
{
	int	i;

	i = -1;
	while (++i < vars->num)
		pthread_detach(vars->philo[i].thread);
	i = -1;
	while (++i < vars->num)
		pthread_mutex_destroy(&vars->fork[i]);
	pthread_mutex_destroy(&vars->print);
	free(vars->fork);
	free(vars->philo);
}

int	ft_threads(t_const_var *vars)
{
	int	i;

	i = -1;
	vars->start_time = get_time();
	while (++i < vars->num)
	{
		vars->philo[i].last_ate = get_time();
		if (pthread_create(&vars->philo[i].thread, NULL,
				ft_routine, &(vars->philo[i])))
			return (0);
	}
	ft_check_cond(vars);
	ft_exit(vars);
	return (1);
}
