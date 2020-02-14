/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:54:25 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/14 17:05:30 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		init_env(t_env *env)
{
	if ((env->mlx = mlx_init()) == (void *)0)
		return ;
	env->pos.x = 0;
	env->pos.y = 0;
	env->iter = 1;
	env->julia_var = 0;
	env->julia.x = -0.8;
	env->julia.y = 0.156;
	env->mandel.im = 0;
	env->mandel.re = 0;
	env->zoom = 1.2;
}

static void		display_usage(void)
{
	ft_putendl("");
	ft_putendl("usage: ./fractol [fractal name]");
	ft_putendl("fractal names:");
	ft_putendl("--> Mandelbrot");
	ft_putendl("--> Julia");
	ft_putendl("--> Ship");
}

static int		validate_input(t_env *env, char *av)
{
	if (ft_strcmp(av, "Ship") == 0)
	{
		env->proj_num = 1;
		return (1);
	}
	else if (ft_strcmp(av, "Julia") == 0)
	{
		env->proj_num = 2;
		return (1);
	}
	else if (ft_strcmp(av, "Mandelbrot") == 0)
	{
		env->proj_num = 3;
		return (1);
	}
	else
		return (0);
}

int				main(int ac, char **av)
{
	t_env		*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (-1);
	if (ac == 2 && validate_input(env, av[1]) == 1)
	{
		init_env(env);
		env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "msuarez- FRACTOL");
		if (env->win == (void *)0)
			return (-1);
		draw_again(env);
		mlx_hook(env->win, 2, 0, event_key, env);
		mlx_hook(env->win, 6, 0, mouse_move, env);
		mlx_hook(env->win, 4, 0, event_mouse, env);
		mlx_loop(env->mlx);
	}
	else
		display_usage();
	return (0);
}
