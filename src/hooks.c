/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:38:39 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/15 08:38:41 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	destroy_window(void *param)
{
	t_bounds	*bounds;

	bounds = param;
	destroy_all(bounds);
	exit(EXIT_SUCCESS);
}

static int	handle_key(int key, t_bounds *bounds)
{
	if (key == 69 || key == 24)
		zoom(bounds, 0.5);
	else if (key == 78 || key == 27)
		zoom(bounds, 2);
	else if (key == 124)
		move(bounds, 'R', 0.3);
	else if (key == 125)
		move(bounds, 'D', 0.3);
	else if (key == 123)
		move (bounds, 'L', 0.3);
	else if (key == 126)
		move (bounds, 'U', 0.3);
	else if (key == 37)
	{
		if (bounds->dynamic == 0)
			bounds->dynamic = 1;
		else
			bounds->dynamic = 0;
	}
	else
		return (0);
	return (1);
}

int	deal_key(int key, void *param)
{
	t_bounds	*bounds;

	bounds = param;
	if (key == 12)
		bounds->cr -= 0.1;
	else if (key == 13)
		bounds->cr += 0.1;
	else if (key == 31)
		bounds->ci -= 0.1;
	else if (key == 35)
		bounds->ci += 0.1;
	else if (key == 8)
	{
		bounds->color = (bounds->color + 1) % 5;
		set_color(bounds);
	}
	else if (key == 53)
	{
		destroy_all(bounds);
		exit(EXIT_SUCCESS);
	}
	else if (!handle_key(key, bounds))
		return (0);
	draw_fractal(bounds);
	return (0);
}

int	mouse_button(int key, int x, int y, void *param)
{
	t_bounds	*bounds;

	bounds = param;
	if (key == 4)
	{
		zoom(bounds, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(bounds, 'L', (double)-x / WIDTH);
		else if (x > 0)
			move(bounds, 'R', (double)x / WIDTH);
		if (y < 0)
			move(bounds, 'U', (double)-y / HEIGHT);
		else if (y > 0)
			move(bounds, 'D', (double)y / HEIGHT);
	}
	else if (key == 5)
		zoom(bounds, 2);
	draw_fractal(bounds);
	return (0);
}

int	change_julia(int x, int y, void *param)
{
	t_bounds	*bounds;

	bounds = param;
	if (bounds->dynamic)
	{
		bounds->cr = -1.5 + 2.5 * (double)x / WIDTH;
		bounds->ci = -1 + 2 * (double)y / HEIGHT;
		draw_fractal(bounds);
	}
	return (0);
}
