/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:55:24 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/17 17:52:22 by msuarez-         ###   ########.fr       */
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
# define RIGHT 124
# define LEFT 123
# define W 13
# define S 1
# define K 40
# define L 37
# define R 15

typedef struct	s_mandel
{
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	double	re;
	double	im;
}				t_mandel;

typedef struct	s_complex
{
	double x;
	double y;
}				t_complex;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*img_data;
	int				size_line;
	int				endian;
	int				iter;
	int				proj_num;
	int				julia_var;
	int				start;
	t_mandel		mandel;
	t_complex		julia;
	t_complex		pos;
	t_complex		mouse;
	long double		zoom;
}				t_env;

int				event_mouse(int button, int x, int y, t_env *e);
int				event_key(int keycode, t_env *e);
int				mouse_move(int x, int y, t_env *e);
void			pixel_put(t_env *env, int x, int y, int color);
void			burning_ship(t_env *env, int times);
void			julia_set(t_complex c, int n, t_env *env);
void			mandelbrot_set(t_env *env, int iter);
void			draw_again(t_env *e);
void			init_img(t_env *env);
void			colors(t_env *env, int xy[2], int i, int iter);
void			pix_to_img(t_env *env, int xy[2], int color);

#endif
