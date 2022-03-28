/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:04:07 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/28 12:29:30 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "ft_printf.h"
# include "mlx.h"
# define WIDTH 1000
# define HEIGHT 1200
# define MAX_ITER 80

typedef struct s_bounds
{
	double	re_start;
	double	re_end;
	double	im_start;
	double	im_end;
	char	fractal;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*buffer;
	double	cr;
	double	ci;
	int		dynamic;
	int		color;
	int		color_set[MAX_ITER + 1];
}					t_bounds;

int		destroy_window(void *param);
int		deal_key(int key, void *param);
int		change_julia(int x, int y, void *param);
int		mouse_button(int key, int x, int y, void *param);

char	parse_fractal(char *s);
void	draw_fractal(t_bounds *b);
void	zoom(t_bounds *bounds, double zoom_size);
void	move(t_bounds *bounds, char dir, double size);
int		quit(void);
void	destroy_all(t_bounds *param);

void	set_color(t_bounds *bounds);
int		fractal(t_bounds *bounds, double cr, double ci);

#endif
