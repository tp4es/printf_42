/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:55:24 by tide-oli          #+#    #+#             */
/*   Updated: 2026/02/12 23:46:14 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	options(int c, va_list args)
{
	if (c == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_printstring(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_printvoid(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_printnumbers(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printnumbers(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_printhex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_printhex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_printchar('c'));
	return (-2);
}
