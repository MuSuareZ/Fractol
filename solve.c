/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:01:45 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/12 15:31:10 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	// else
	// 	pixel_put(env, xy[0], xy[1], 0x3399ff);
}

void			pixel_put(t_env *env, int x, int y, int color)
{
	mlx_pixel_put(env->mlx, env->win, x, y, color);
}
