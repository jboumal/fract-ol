/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:33:09 by jboumal           #+#    #+#             */
/*   Updated: 2022/01/24 21:33:11 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static void	rec_write_int(int n, t_flags *flags)
{
	if (n != 0)
	{
		flags->printed ++;
		rec_write_int(n / 10, flags);
		ft_putchar_fd (ft_abs(n % 10) + '0', 1);
	}
	else if (flags->negative)
	{
		flags->printed ++;
		ft_putchar_fd('-', 1);
	}
}

static void	rec_write_uint(unsigned int n, t_flags *flags)
{
	if (n != 0)
	{
		flags->printed ++;
		rec_write_uint(n / 10, flags);
		ft_putchar_fd (n % 10 + '0', 1);
	}
}

void	write_i(int n, t_flags *flags)
{
	if (n == 0)
	{
		flags->printed ++;
		ft_putchar_fd('0', 1);
	}
	else
	{
		if (n < 0)
			flags->negative = 1;
		rec_write_int(n, flags);
	}
}

void	write_u(unsigned int n, t_flags *flags)
{
	if (n == 0)
	{
		flags->printed ++;
		ft_putchar_fd('0', 1);
	}
	else
	{
		rec_write_uint(n, flags);
	}
}
