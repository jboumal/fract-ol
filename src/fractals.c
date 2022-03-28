/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 07:47:44 by jboumal           #+#    #+#             */
/*   Updated: 2022/02/06 07:47:48 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	julia(double zr, double zi, double cr, double ci)
{
	int		n;
	double	temp;

	n = 0;
	while (n < MAX_ITER && (zi * zi + zr * zr) <= 4.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = temp;
		n++;
	}
	return (n);
}

int	burning_ship(double cr, double ci)
{
	int		n;
	double	zi;
	double	zr;
	double	temp;

	n = 0;
	zr = 0;
	zi = 0;
	while (n < MAX_ITER && (zi * zi + zr * zr) <= 4.0)
	{
		zr = fabs(zr);
		zi = fabs(zi);
		temp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = temp;
		n++;
	}
	return (n);
}

int	mandelbrot(double cr, double ci)
{
	int		n;
	double	zi;
	double	zr;
	double	temp;

	n = 0;
	zr = 0;
	zi = 0;
	while (n < MAX_ITER && (zi * zi + zr * zr) <= 4.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = temp;
		n++;
	}
	return (n);
}

int	fractal(t_bounds *bounds, double cr, double ci)
{
	if (bounds->fractal == 'M')
		return (mandelbrot(cr, ci));
	if (bounds->fractal == 'B')
		return (burning_ship(cr, ci));
	else if (bounds->fractal == 'J')
		return (julia(cr, ci, bounds->cr, bounds->ci));
	return (0);
}
