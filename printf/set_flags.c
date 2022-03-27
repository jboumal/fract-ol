/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:03:55 by jboumal           #+#    #+#             */
/*   Updated: 2022/01/21 15:03:57 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	init_flags(t_flags *flags)
{
	flags->negative = 0;
	flags->printed = 0;
	flags->format = '\0';
	flags->size = 0;
}

void	set_flags(t_flags *flags, const char *format)
{
	init_flags(flags);
	if (format [1])
		flags->format = format[1];
	flags->size = 2;
}
