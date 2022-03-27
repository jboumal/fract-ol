/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:24:04 by jboumal           #+#    #+#             */
/*   Updated: 2022/01/15 16:24:39 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int		negative;
	int		printed;
	int		size;
	char	format;
}					t_flags;

int		ft_printf(const char *format, ...);
void	set_flags(t_flags *flags, const char *format);
void	write_c(char c, t_flags *flags);
void	write_s(char *s, t_flags *flags);
void	write_p(void *p, t_flags *flags);
void	write_i(int n, t_flags *flags);
void	write_u(unsigned int n, t_flags *flags);
void	write_x(unsigned int n, t_flags *flags);
void	write_upper_x(unsigned int n, t_flags *flags);
void	write_percent(t_flags *flags);

#endif
