/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:38:33 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/20 18:03:58 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			event_key_next(int keycode, t_env *e)
{
	if (keycode == R)
	{
		e->zoom = 1.2;
		e->julia.x = -0.8;
		e->julia.y = 0.156;
	}
	if (keycode == L && e->julia_var == 1)
		e->julia_var = 0;
	if (keycode == K && e->julia_var == 0)
		e->julia_var = 1;
	draw_again(e);
	return (1);
}

int			event_key(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == RIGHT)
		e->pos.x -= 0.3 / e->zoom;
	if (keycode == S && e->iter != 1)
		e->iter -= 2;
	if (keycode == LEFT)
		e->pos.x += 0.3 / e->zoom;
	if (keycode == W & e->iter < 1000)
		e->iter += 2;
	if (keycode == UP)
		e->pos.y += 0.3 / e->zoom;
	if (keycode == DOWN)
		e->pos.y -= 0.3 / e->zoom;
	return (event_key_next(keycode, e));
}

int			mouse_move(int x, int y, t_env *e)
{
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{
		e->mouse.x = x;
		e->mouse.y = y;
		if (e->julia_var == 1 && e->proj_num == 2)
		{
			e->mouse.x = -1.0 * x / (WIDTH);
			e->mouse.y = 1.0 * y / (HEIGHT);
			e->julia.x = e->mouse.x;
			e->julia.y = e->mouse.y;
		}
	}
	draw_again(e);
	return (1);
}

int			event_mouse(int button, int x, int y, t_env *e)
{
	if (x && y && button == SCROLL_UP)
		e->zoom *= 0.5;
	if (x && y && button == SCROLL_DOWN)
		e->zoom /= 0.5;
	draw_again(e);
	return (1);
}
