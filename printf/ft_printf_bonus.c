/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:18:57 by jboumal           #+#    #+#             */
/*   Updated: 2022/01/15 16:25:16 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static void	write_arg(va_list ap, t_flags *flags, const char *format)
{
	set_flags(flags, format);
	if (flags->format == 'c')
		write_c((char)va_arg(ap, int), flags);
	if (flags->format == 's')
		write_s(va_arg(ap, char *), flags);
	if (flags->format == 'p')
		write_p(va_arg(ap, void *), flags);
	if (flags->format == 'd')
		write_i(va_arg(ap, int), flags);
	if (flags->format == 'i')
		write_i(va_arg(ap, int), flags);
	if (flags->format == 'u')
		write_u(va_arg(ap, unsigned int), flags);
	if (flags->format == 'x')
		write_x(va_arg(ap, unsigned int), flags);
	if (flags->format == 'X')
		write_upper_x(va_arg(ap, unsigned int), flags);
	if (flags->format == '%')
		write_percent(flags);
	minus_flag(flags);
}

static int	initialized_printf(va_list ap, t_flags *flags, const char *format)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			i++;
			printed++;
		}
		else
		{
			write_arg(ap, flags, format + i);
			i += flags->size;
			printed += flags->printed;
		}
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	t_flags	*flags;
	va_list	ap;
	int		printed;

	printed = 0;
	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (0);
	va_start(ap, format);
	printed = initialized_printf(ap, flags, format);
	va_end(ap);
	free(flags);
	return (printed);
}
