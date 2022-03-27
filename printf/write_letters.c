/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:54:31 by jboumal           #+#    #+#             */
/*   Updated: 2022/01/24 00:54:34 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	write_percent(t_flags *flags)
{
	flags->printed = 1;
	ft_putchar_fd('%', 1);
}

void	write_c(char c, t_flags *flags)
{
	ft_putchar_fd(c, 1);
	flags->printed = 1;
}

void	write_s(char *s, t_flags *flags)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		flags->printed = 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		flags->printed = ft_strlen(s);
	}
}
