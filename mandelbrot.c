/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:22:39 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/12 15:31:04 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			mandelbrot_set(t_env *env, int iter)
{
	int			i;
	int			xy[2];
	double		pr;
	double		pi;
	double		newRe;
	double		newIm;
	double		oldRe;
	double		oldIm;

	xy[1] = 0;
	while (xy[1]++ < HEIGHT)
	{
		xy[0] = 0;
		while (xy[0]++ < WIDTH)
		{
			pr = 2.0 * (xy[0] - WIDTH / 2) / (0.5 * env->zoom * WIDTH) + env->pos.x;
			pi = 2.0 * (xy[1] - HEIGHT / 2) / (0.5 * env->zoom * HEIGHT) + env->pos.y;
			newRe = newIm = oldRe = oldIm = 0;
			i = 0;
			while (i++ < iter)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = 2 * oldRe * oldIm + pi;
				if ((newRe * newRe + newIm * newIm) > 4)
					break ;
			}
			colors(env, xy, i, iter);
		}
	}
}
