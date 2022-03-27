/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:03:55 by jboumal           #+#    #+#             */
/*   Updated: 2022/01/21 15:03:57 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->fill_char = ' ';
	flags->number_sign = 0;
	flags->dot = -1;
	flags->plus = 0;
	flags->space = 0;
	flags->width = 0;
	flags->printed = 0;
	flags->format = '\0';
	flags->size = 0;
	flags->tmp = 0;
	flags->negative = 0;
}

static int	set_width(t_flags *flags, const char *format)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (ft_isdigit(format[i]))
	{
		width = width * 10 + format[i] - '0';
		i++;
	}
	if (width != 0)
		flags->width = width;
	return (i);
}

static int	set_dot(t_flags *flags, const char *format)
{
	int	i;
	int	dot;

	i = 1;
	dot = 0;
	while (ft_isdigit(format[i]))
	{
		dot = dot * 10 + format[i] - '0';
		i++;
	}
	flags->dot = dot;
	return (i);
}

void	set_flags(t_flags *flags, const char *format)
{
	int	i;

	i = 0;
	init_flags(flags);
	while (format[++i] && !ft_strchr("cspdiuxX%", format[i]))
	{
		if (format[i] == '-')
			flags->minus = 1;
		else if (format[i] == '0')
			flags->fill_char = '0';
		else if (format[i] == '#')
			flags->number_sign = 1;
		else if (format[i] == '+')
			flags->plus = 1;
		else if (format[i] == ' ')
			flags->space = 1;
		else if (format[i] == '.')
			i += set_dot(flags, format + i) - 1;
		else
			i += set_width(flags, format + i) - 1;
	}
	flags->format = format[i];
	if (flags->dot >= 0)
		flags->fill_char = ' ';
	flags->size = i + 1;
}
