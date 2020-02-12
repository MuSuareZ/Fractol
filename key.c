/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:38:33 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/12 17:50:50 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// int			event_key_next(int keycode, t_env *e)
// {
// 	draw_again(e);
// 	return (1);
// }

int			event_key(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == D)
		e->pos.x -= 0.3 / e->zoom;
	if (keycode == DOWN && e->iter != 1)
		e->iter -= 2;
	if (keycode == A)
		e->pos.x += 0.3 / e->zoom;
	if (keycode == UP & e->iter < 200)
		e->iter += 2;
	if (keycode == W)
		e->pos.y += 0.3 / e->zoom;
	if (keycode == S)
		e->pos.y -= 0.3 / e->zoom;
	if (keycode == L && e->julia_var == 1)
		e->julia_var = 0;
	if (keycode == K && e->julia_var == 0)
		e->julia_var = 1;
	draw_again(e);
	return (1);
}

int		mouse_move(int x, int y, t_env *e)
{
	if (e->julia_var == 1)
	{
		e->julia.x -= 0.1;
		e->julia.y += 0.3;
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
