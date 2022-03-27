/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:03:53 by jboumal           #+#    #+#             */
/*   Updated: 2022/01/24 18:03:55 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static void	rec_write_pointer(size_t ptr, t_flags *flags)
{
	char	base[16];

	ft_strlcpy(base, "0123456789abcdef", 17);
	if (!ptr)
	{
		flags->printed += 2;
		field_width(flags);
		ft_putstr_fd("0x", 1);
	}
	else
	{
		flags->printed ++;
		rec_write_pointer(ptr / 16, flags);
		ft_putchar_fd (base[ptr % 16], 1);
	}
}

void	write_p(void *p, t_flags *flags)
{
	size_t	ptr;

	ptr = (size_t) p;
	if (!ptr)
	{
		if (flags->dot == 0)
		{
			flags->printed = 2;
			field_width(flags);
			ft_putstr_fd("0x", 1);
		}
		else
		{
			flags->printed = 3;
			field_width(flags);
			ft_putstr_fd("0x0", 1);
		}
	}
	else
		rec_write_pointer(ptr, flags);
}
