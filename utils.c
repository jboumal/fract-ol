/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:50:38 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/15 08:50:40 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	destroy_all(t_bounds *bounds)
{
	mlx_destroy_image(bounds->mlx_ptr, bounds->img_ptr);
	mlx_destroy_window(bounds->mlx_ptr, bounds->win_ptr);
	free(bounds->mlx_ptr);
	free(bounds);
}

char	parse_fractal(char *s)
{
	if (ft_strncmp(s, "M", 2) == 0 || ft_strncmp(s, "m", 2) == 0)
		return ('M');
	else if (ft_strncmp(s, "J", 2) == 0 || ft_strncmp(s, "j", 2) == 0)
		return ('J');
	else if (ft_strncmp(s, "B", 2) == 0 || ft_strncmp(s, "b", 2) == 0)
		return ('B');
	else
	{
		quit();
		exit(EXIT_SUCCESS);
	}
}

int	quit(void)
{
	ft_printf("Please provide the fractal that you want to display.\n");
	ft_printf("List of available fractals:\n");
	ft_printf("[M] Mandelbrot\n");
	ft_printf("[J] Julia\n");
	ft_printf("[B] Burning ships\n");
	return (0);
}

void	zoom(t_bounds *bounds, double zoom_size)
{
	double	width;
	double	height;

	width = bounds->re_end - bounds->re_start;
	height = bounds->im_end - bounds->im_start;
	bounds->re_start = bounds->re_start + (width - zoom_size * width) / 2;
	bounds->re_end = bounds->re_start + zoom_size * width;
	bounds->im_start = bounds->im_start + (height - zoom_size * height) / 2;
	bounds->im_end = bounds->im_start + zoom_size * height;
}

void	move(t_bounds *bounds, char dir, double size)
{
	double	width;
	double	height;

	width = bounds->re_end - bounds->re_start;
	height = bounds->im_end - bounds->im_start;
	if (dir == 'R')
	{
		bounds->re_start += width * size;
		bounds->re_end += width * size;
	}
	else if (dir == 'L')
	{
		bounds->re_start -= width * size;
		bounds->re_end -= width * size;
	}
	else if (dir == 'D')
	{
		bounds->im_start += height * size;
		bounds->im_end += height * size;
	}
	else if (dir == 'U')
	{
		bounds->im_start -= height * size;
		bounds->im_end -= height * size;
	}
}
