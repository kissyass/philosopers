/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:32:20 by ykissiko          #+#    #+#             */
/*   Updated: 2023/04/01 13:41:31 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_malloc(int s, int n)
{
	void	*p;

	p = malloc(s * n);
	if (!p)
		return (NULL);
	return (p);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
}

unsigned long	ft_time(t_const_var *vars)
{
	return (get_time() - vars->start_time);
}

int	ft_compare(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_print(t_const_var *vars, char *str, int id)
{
	unsigned long	time;

	time = ft_time(vars);
	pthread_mutex_lock(&vars->print);
	if (vars->stop == 0 && vars->ate_num != vars->num)
		printf("%lu %d %s\n", time, id, str);
	if (ft_compare(str, "died") == 1)
		printf("%lu %d %s\n", time, id, str);
	pthread_mutex_unlock(&vars->print);
}
