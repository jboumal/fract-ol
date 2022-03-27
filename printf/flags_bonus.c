/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:19:31 by jboumal           #+#    #+#             */
/*   Updated: 2022/01/25 02:19:34 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

void	minus_flag(t_flags *flags)
{
	while (flags->minus && flags->width > flags->printed)
	{
		ft_putchar_fd(flags->fill_char, 1);
		flags->printed ++;
	}
}

void	precision(t_flags *flags)
{
	if (flags->dot >= 0 && flags->negative)
		flags->dot ++;
	while (flags->dot > flags->printed)
	{
		flags->tmp ++;
		flags->printed ++;
	}
}

static void	put_sign(t_flags *flags)
{
	if (flags->negative)
		ft_putchar_fd('-', 1);
	else if (flags->plus)
		ft_putchar_fd('+', 1);
	else if (flags->space)
		ft_putchar_fd(' ', 1);
}

void	field_width(t_flags *flags)
{
	if (flags->fill_char == '0')
	{
		put_sign(flags);
	}
	while (!flags->minus && flags->width > flags->printed)
	{
		ft_putchar_fd(flags->fill_char, 1);
		flags->printed ++;
	}
	if (flags->fill_char == ' ')
		put_sign(flags);
	while (flags->tmp > 0)
	{
		ft_putchar_fd('0', 1);
		flags->tmp --;
	}
}
