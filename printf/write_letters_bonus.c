/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_letters_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:54:31 by jboumal           #+#    #+#             */
/*   Updated: 2022/01/24 00:54:34 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

void	write_percent(t_flags *flags)
{
	flags->printed = 1;
	field_width(flags);
	ft_putchar_fd('%', 1);
}

void	write_c(char c, t_flags *flags)
{
	flags->printed = 1;
	field_width(flags);
	ft_putchar_fd(c, 1);
}

void	write_s(char *s, t_flags *flags)
{
	char	*s2;

	if (!s)
	{
		flags->printed = 6;
		if (flags->dot >= 0 && flags->dot < 6)
			flags->printed = flags->dot;
		s2 = malloc(sizeof(char) * flags->printed + 1);
		if (!s2)
			return ;
		ft_strlcpy(s2, "(null)", flags->printed + 1);
	}
	else
	{
		flags->printed = ft_strlen(s);
		if (flags->dot >= 0 && flags->dot < (int)ft_strlen(s))
			flags->printed = flags->dot;
		s2 = malloc(sizeof(char) * flags->printed + 1);
		if (!s2)
			return ;
		ft_strlcpy(s2, s, flags->printed + 1);
	}
	field_width(flags);
	ft_putstr_fd(s2, 1);
	free(s2);
}
