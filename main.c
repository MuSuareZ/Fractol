/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:54:25 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/10 18:52:34 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		init_env(t_env *env)
{
	if ((env->mlx = mlx_init()) == (void *)0)
		return ;
	env->pos.x = 0;
	env->pos.y = 0;
	env->c_min.x = -2.5;
	env->c_min.y = -2.0;
	env->c_max.x = 1.5;
	env->c_max.y = 2.0;
	env->iter = 0;
	env->julia.x = -0.8;
	env->julia.y = 0.156;
	env->mandelbrot.x = -0.8;
	env->mandelbrot.y = 0.156;
	env->esc_radius_squared = 4;
	env->pixel_height = (env->c_max.y - env->c_min.y) / HEIGHT;
	env->pixel_width = (env->c_max.x - env->c_min.x) / WIDTH;
	env->zoom = 1.2;
}

static void		display_usage(void)
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
	if (ft_strcmp(av, "Koch") == 0)
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
		// init_img(env);
		env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "msuarez- FRACTOL");
		if (env->win == (void *)0)
			return (-1);
		draw_again(env);
		mlx_hook(env->win, 2, 0, event_key, env);
		mlx_mouse_hook(env->win, event_mouse, env);
		mlx_loop(env->mlx);
	}
	else
		display_usage();
	return (0);
}
