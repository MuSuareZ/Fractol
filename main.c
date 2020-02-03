/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:54:25 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/03 17:31:02 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		init_env(t_env *env)
{
	t_coord p1;
	t_coord p2;
	
	if ((env->mlx = mlx_init()) == (void *)0)
		return ;
	env->iter = 1;
	env->proj_num = 1;
	env->p1 = (t_coord){300,HEIGHT-300};
	env->p2 = (t_coord){WIDTH-300,HEIGHT-300};
}

static void		display_usage()
{
	ft_putendl("");
	ft_putendl("usage: ./fractol [fractal name]");
	ft_putendl("fractal names:");
	ft_putendl("--> Mandelbrot");
	ft_putendl("--> Julia");
	ft_putendl("--> Koch");
}

static int		validate_input(t_env *env, char *av)
{
	if (ft_strcmp(av, K) == 0)
	{
		env->proj_num = 1;
		return (1);
	}
	else if (ft_strcmp(av, J) == 0)
	{
		env->proj_num = 2;
		return (1);
	}
	else if (ft_strcmp(av, M) == 0)
	{
		env->proj_num = 3;
		return (1);
	}
	else
		return (0);
}

int		main(int ac, char **av)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
			return (-1);
	if (ac == 2 && validate_input(env, av[1]) == 1)
	{
		init_env(env);
		env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "msuarez- FRACTOL");
		if (env->win == (void *)0)
			return (-1);
		koch_curve(env, env->p1, env->p2, env->iter);
		mlx_key_hook(env->win, event_key, env);
		//mlx_mouse_hook(env->win, event_mouse, env);
		mlx_loop(env->mlx);
	}
	else
		display_usage();
	return (0);
}
