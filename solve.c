/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:01:45 by msuarez-          #+#    #+#             */
/*   Updated: 2020/03/09 16:03:37 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <pthread.h>

static void		copy_node(t_env *copy, t_env *node, int i)
{
	ft_memcpy(copy, node, sizeof(t_env));
	copy->thread_id = i;
}

static void		*which_fract(void *data)
{
	t_env	*node;

	node = (t_env *)data;
	if (node->proj_num == 1)
		burning_ship(node);
	else if (node->proj_num == 2)
		julia_set(node);
	else if (node->proj_num == 3)
		mandelbrot_set(node);
	return (NULL);
}

void			draw_again(t_env *e)
{
	pthread_t	*threads;
	t_env		*copies[THREADS];
	int			i;

	i = 0;
	threads = malloc(sizeof(pthread_t) * THREADS);
	clear_img(e);
	while (i < THREADS)
	{
		copies[i] = (t_env *)malloc(sizeof(t_env));
		copy_node(copies[i], e, i);
		pthread_create(&threads[i], NULL, which_fract, copies[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i], NULL);
		free(copies[i]);
		i++;
	}
	free(threads);
	mlx_put_image_to_window(e->mlx, e->win, e->img.image, 0, 0);
	draw_info(e);
}

void			draw_info(t_env *e)
{
	char	*tmp;

	tmp = ft_itoa(e->iter);
	mlx_string_put(e->mlx, e->win, 10, 22, 0x00FFFFFF, "Iterations :");
	mlx_string_put(e->mlx, e->win, 140, 22, 0x00FFFFFF, tmp);
	free(tmp);
	tmp = ft_itoa(e->julia_var);
	mlx_string_put(e->mlx, e->win, 10, 44, 0x00FFFFFF, "Julia Var  :");
	mlx_string_put(e->mlx, e->win, 140, 44, 0x00FFFFFF, tmp);
	free(tmp);
	tmp = ft_itoa(e->mouse.x);
	mlx_string_put(e->mlx, e->win, 10, 66, 0x00FFFFFF, "Mouse X    :");
	mlx_string_put(e->mlx, e->win, 140, 66, 0x00FFFFFF, tmp);
	free(tmp);
	tmp = ft_itoa(e->mouse.y);
	mlx_string_put(e->mlx, e->win, 10, 88, 0x00FFFFFF, "Mouse Y    :");
	mlx_string_put(e->mlx, e->win, 140, 88, 0x00FFFFFF, tmp);
	free(tmp);
}
