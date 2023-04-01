/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:29:36 by ykissiko          #+#    #+#             */
/*   Updated: 2023/04/01 13:47:37 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

struct	s_const_var;

typedef struct s_philo
{
	int					id;
	int					ate;
	struct s_const_var	*var;
	pthread_mutex_t		*fork;
	unsigned long		last_ate;
	pthread_t			thread;
}	t_philo;

typedef struct s_const_var
{
	int				num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				max_eat;
	int				ate_num;
	unsigned long	start_time;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	int				stop;
}	t_const_var;

int				ft_check_params(char **argv, t_const_var *vars);
int				ft_int(char *num);
int				ft_init_params(t_const_var *vars);
int				ft_init_mutex(t_const_var *vars);
int				ft_init_philo(t_const_var *vars);
int				ft_threads(t_const_var *vars);
unsigned long	get_time(void);
void			ft_print(t_const_var *vars, char *str, int id);
unsigned long	ft_time(t_const_var *vars);
void			*ft_malloc(int s, int n);
void			*ft_routine(void *p);
void			ft_check_cond(t_const_var *vars);
void			ft_exit(t_const_var *vars);
int				ft_compare(char *str1, char *str2);
void			ft_eat(t_philo *philo, t_const_var *vars);
void			ft_sleep(unsigned long time, t_const_var *vars);

#endif
