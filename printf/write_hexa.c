/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:32:56 by jboumal           #+#    #+#             */
/*   Updated: 2022/01/24 21:32:59 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	rec_write_hex(unsigned int n, t_flags *flags, char *base)
{
	if (n != 0)
	{
		flags->printed ++;
		rec_write_hex(n / 16, flags, base);
		ft_putchar_fd (base[n % 16], 1);
	}
}

void	write_x(unsigned int n, t_flags *flags)
{
	if (n == 0)
	{
		flags->printed = 1;
		ft_putchar_fd('0', 1);
	}
	else
		rec_write_hex(n, flags, "0123456789abcdefg");
}

void	write_upper_x(unsigned int n, t_flags *flags)
{
	if (n == 0)
	{
		flags->printed = 1;
		ft_putchar_fd('0', 1);
	}
	else
		rec_write_hex(n, flags, "0123456789ABCDEFG");
}
