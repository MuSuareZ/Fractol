/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:01:45 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/13 15:24:50 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_again(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_string_put(e->mlx, e->win, 10, 5, 0xFFFFFF, \
						ft_strjoin("Number of iterations : ", \
						ft_itoa(e->iter)));
	mlx_string_put(e->mlx, e->win, 10, 35, 0xFFFFFF, \
						ft_strjoin("Zoom level: x", \
						ft_itoa(e->zoom)));
	mlx_string_put(e->mlx, e->win, 10, 65, 0xFFFFFF, \
						ft_strjoin("Julia Var: ", \
						ft_itoa(e->julia_var)));					
	if (e->proj_num == 1)
	{
		koch_curve(e, (t_coord){600*e->zoom, 500*e->zoom},
					(t_coord){400*e->zoom, 500*e->zoom}, e->iter);
		koch_curve(e, (t_coord){400*e->zoom, 500*e->zoom},
					(t_coord){500*e->zoom, 300*e->zoom}, e->iter);
		koch_curve(e, (t_coord){500*e->zoom, 300*e->zoom},
					(t_coord){600*e->zoom, 500*e->zoom}, e->iter);
	}
	else if (e->proj_num == 2)
		julia_set(e->julia, e->iter, e);
	else
		mandelbrot_set(e, e->iter);
}

void	colors(t_env *env, int xy[2], int i, int iter)
{
	if (i > iter)
		pixel_put(env, xy[0], xy[1], 0xff6600);
	else if (i > iter * 0.6)
		pixel_put(env, xy[0], xy[1], 0xff6600);
	else if (i > iter * 0.5)
		pixel_put(env, xy[0], xy[1], 0xffff00);
	else if (i > iter * 0.4)
		pixel_put(env, xy[0], xy[1], 0xffff33);
	else if (i > iter * 0.3)
		pixel_put(env, xy[0], xy[1], 0xffff80);
	else if (i > iter * 0.2)
		pixel_put(env, xy[0], xy[1], 0xffffb3);
}

void			pixel_put(t_env *env, int x, int y, int color)
{
	mlx_pixel_put(env->mlx, env->win, x, y, color);
}
