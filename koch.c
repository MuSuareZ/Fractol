/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:51:05 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/04 18:18:02 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_again(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (e->proj_num == 1)
		koch_curve(e, e->p1, e->p2, e->iter);
	else if (e->proj_num == 2)
		julia_set(e->julia, 2.0, e->iter, e);
	// else if (e->proj_num == 3)
}

static void		draw_line(t_env *e, t_coord src, t_coord dst)
{
	t_coord		delta;
	float		s[2];
	float		err[2];

	delta.x = ft_abs(dst.x - src.x);
	delta.y = ft_abs(dst.y - src.y);
	s[0] = (src.x < dst.x ? 1 : -1);
	s[1] = (src.y < dst.y ? 1 : -1);
	err[0] = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	while (src.x != dst.x || src.y != dst.y)
	{
		pixel_put(e, src.x, src.y, 0x6ffff);
		err[1] = err[0];
		if (err[1] > -delta.x)
		{
			err[0] -= delta.y;
			src.x += s[0];
		}
		if (err[1] < delta.y)
		{
			err[0] += delta.x;
			src.y += s[1];
		}
	}
}

void	koch_curve(t_env *env, t_coord p1, t_coord p2, int times)
{
	t_coord		p3;
	t_coord		p4;
	t_coord		p5;
	double		theta;

	theta = M_PI / 3;
	if (times > 0)
	{
		p3 = (t_coord){(2 * p1.x + p2.x) / 3, (2 * p1.y + p2.y) / 3};
		p5 = (t_coord){(2 * p2.x + p1.x) / 3, (2 * p2.y + p1.y) / 3};
		p4 = (t_coord){p3.x + (p5.x - p3.x) * cos(theta) + (p5.y - p3.y)
		* sin(theta), p3.y - (p5.x - p3.x) * sin(theta) + (p5.y - p3.y)
		* cos(theta)};
		koch_curve(env, p1, p3, times - 1);
		koch_curve(env, p3, p4, times - 1);
		koch_curve(env, p4, p5, times - 1);
		koch_curve(env, p5, p2, times - 1);
	}
	else
		draw_line(env, p1, p2);
}
