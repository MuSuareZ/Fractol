/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:55:24 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/04 18:09:56 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"

# define ESC 53
# define WIDTH 1000
# define HEIGHT 1000
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define UP 126
# define DOWN 125
# define WHITE 0xFFFFFF

typedef struct	s_complex
{
	double x;
	double y;
}				t_complex;

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	int		iter;
	int		proj_num;
	t_coord		p1;
	t_coord		p2;
	t_complex		julia;
	int		zoom;
}					t_env;

int		event_mouse(int button, int x, int y, t_env *e);
int		event_key(int keycode, t_env *e);
void	pixel_put(t_env *env, int x, int y, int color);
void	koch_curve(t_env *env, t_coord p1, t_coord p2, int times);
void	julia_set(t_complex c, double radius, int n, t_env *env);
void	draw_again(t_env *e);

#endif
