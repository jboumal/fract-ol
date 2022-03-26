/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:03:43 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/26 14:44:32 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	init_image(t_bounds *b)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;

	b->img_ptr = mlx_new_image(b->mlx_ptr, WIDTH, HEIGHT);
	if (!b->img_ptr)
	{
		mlx_destroy_window(b->mlx_ptr, b->win_ptr);
		free(b->mlx_ptr);
		free(b);
		exit(EXIT_FAILURE);
	}
	buffer = mlx_get_data_addr(b->img_ptr, &pixel_bits, &line_bytes, &endian);
	b->buffer = buffer;
}

void	init(t_bounds *bounds, char fract)
{
	bounds->re_start = -1;
	bounds->re_end = 1;
	bounds->im_start = -1.0 * HEIGHT / WIDTH;
	bounds->im_end = 1.0 * HEIGHT / WIDTH;
	bounds->fractal = fract;
	bounds->mlx_ptr = mlx_init();
	if (!bounds->mlx_ptr)
	{
		free(bounds);
		exit(EXIT_FAILURE);
	}
	bounds->win_ptr = mlx_new_window(bounds->mlx_ptr, WIDTH, HEIGHT, "fractol");
	if (!bounds->win_ptr)
	{
		free(bounds->mlx_ptr);
		free(bounds);
		exit(EXIT_FAILURE);
	}
	init_image(bounds);
	bounds->cr = 0;
	bounds->ci = 0;
	bounds->color = 0;
	bounds->dynamic = 1;
	set_color(bounds);
	draw_fractal(bounds);
}

int	main(int argc, char **argv)
{
	t_bounds	*bounds;
	char		fract;
	int			dynamic;

	dynamic = 1;
	if (argc == 1 || argc >= 4)
		return (quit());
	if (argc >= 2)
		fract = parse_fractal(argv[1]);
	bounds = malloc(sizeof (t_bounds));
	if (!bounds)
		return (0);
	init(bounds, fract);
	if (argc == 3)
		bounds->dynamic = ft_atoi(argv[2]);
	mlx_key_hook(bounds->win_ptr, deal_key, bounds);
	mlx_hook(bounds->win_ptr, 17, 0L, destroy_window, bounds);
	mlx_mouse_hook(bounds->win_ptr, mouse_button, bounds);
	if (bounds->fractal == 'J')
		mlx_hook(bounds->win_ptr, 6, 0L, change_julia, bounds);
	mlx_loop(bounds->mlx_ptr);
	destroy_all(bounds);
	return (0);
}
