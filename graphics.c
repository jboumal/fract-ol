/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:55:13 by jboumal           #+#    #+#             */
/*   Updated: 2022/02/06 18:55:15 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static void	add_pixel(t_bounds *b, int x, int y, int color)
{
	b->buffer[x * 4 + WIDTH * y * 4] = color;
	b->buffer[x * 4 + WIDTH * y * 4 + 1] = color >> 8;
	b->buffer[x * 4 + WIDTH * y * 4 + 2] = color >> 16;
	b->buffer[x * 4 + WIDTH * y * 4 + 3] = color >> 24;
}

void	draw_fractal(t_bounds *b)
{
	int		x;
	int		y;
	double	cr;
	double	ci;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			cr = b->re_start + ((double)x / WIDTH) * (b->re_end - b->re_start);
			ci = b->im_start + ((double)y / HEIGHT) * (b->im_end - b->im_start);
			add_pixel(b, x, y, b->color_set[fractal(b, cr, ci)]);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(b->mlx_ptr, b->win_ptr, b->img_ptr, 0, 0);
}
