/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:38:33 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/03 17:53:48 by msuarez-         ###   ########.fr       */
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
	// if (keycode == RIGHT)
	// 	e->pos.x += 30;
	if (keycode == DOWN && e->iter != 0)
		e->iter -= 1;
	// if (keycode == LEFT)
	// 	e->pos.x -= 30;
	if (keycode == UP)
		e->iter += 1;
	// if (keycode == W)
	// {
	// 	e->alt += 1;
	// 	apply_height(e, 1);
	// }
	// if (keycode == ZOOMIN)
	// {
	// 	e->scale.x += 1;
	// 	e->scale.y -= 1;
	// }
	draw_again(e);
	return (1);
}

int			event_mouse(int button, int x, int y, t_env *e)
{
	if (x && y && button == SCROLL_UP)
	{
		e->zoom++;
	}
	draw_again(e);
	return (0);
}
