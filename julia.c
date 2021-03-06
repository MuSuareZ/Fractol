/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:27:35 by msuarez-          #+#    #+#             */
/*   Updated: 2020/03/09 17:50:06 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static	t_mandel	init_z(t_env *env, t_mandel z, int xy[2])
{
	z.newre = 2.5 * (xy[0] - WIDTH / 2) /
	(0.5 * env->zoom * WIDTH) + env->pos.x;
	z.newim = 2.5 * (xy[1] - HEIGHT / 2) /
	(0.5 * env->zoom * HEIGHT) + env->pos.y;
	return (z);
}

static	t_mandel	calc_z(t_mandel z, t_complex c)
{
	z.oldre = z.newre;
	z.oldim = z.newim;
	z.newre = z.oldre * z.oldre - z.oldim * z.oldim + c.x;
	z.newim = 2 * z.oldre * z.oldim + c.y;
	return (z);
}

void				*julia_set(void *env_ptr)
{
	t_env			*env;
	int				xy[2];
	int				i;
	t_mandel		z;

	env = (t_env*)env_ptr;
	xy[1] = env->thread_id;
	while (xy[1] < HEIGHT)
	{
		xy[0] = 0;
		while (xy[0]++ < WIDTH)
		{
			z = init_z(env, z, xy);
			i = 0;
			while (i++ <= env->iter)
			{
				z = calc_z(z, env->julia);
				if ((z.newre * z.newre + z.newim * z.newim) > 4)
					break ;
			}
			img_pixel_put(env, xy[0], xy[1], select_color(env, i));
		}
		xy[1] += THREADS;
	}
	return (NULL);
}
