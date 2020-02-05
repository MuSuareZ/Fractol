/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:22:39 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/05 17:12:17 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	mandelbrot_set(t_env *env, int iter)
{
	int i;
	int iX;
	int iY;
    t_complex C;
	t_complex Z0;
	t_complex Z1;
    const double CxMin = -2.5;
    const double CxMax = 1.5;
    const double CyMin = -2.0;
    const double CyMax = 2.0;
    double PixelWidth = (CxMax-CxMin) / WIDTH;
    double PixelHeight=(CyMax-CyMin) / HEIGHT;
    const double EscapeRadius = 2;
    double ER2 = EscapeRadius * EscapeRadius;
    for(iY = 0; iY < HEIGHT; iY++)
    {
        C.y = CyMin + iY * PixelHeight;
        if (fabs(C.y)< PixelHeight/2) C.y = 0.0;
        for(iX = 0; iX < WIDTH; iX++)
        {         
            C.x = CxMin + iX * PixelWidth;
            Z0.x = 0.0;
            Z0.y = 0.0;
            Z1.x = Z0.x * Z0.x;
            Z1.y = Z0.y * Z0.y;
            for (i = 0; i < iter && ((Z1.x + Z1.y) < ER2); i++)
            {
                Z0.y = 2 * Z0.x * Z0.y + C.y;
                Z0.x = Z1.x - Z1.y + C.x;
                Z1.x = Z0.x * Z0.x;
                Z1.y = Z0.y * Z0.y;
            };
            if (i==iter)
            { /*  interior of Mandelbrot set = black */
				pixel_put(env, iX, iY, 0xff33cc);                 
            }
			else 
            { /* exterior of Mandelbrot set = white */
				pixel_put(env, iX, iY, 0x000000);
            };
        }
    }
}
