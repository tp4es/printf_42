/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:51:26 by tide-oli          #+#    #+#             */
/*   Updated: 2026/03/13 20:09:23 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		go;

	i = 0;
	go = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			go += options(format[i], args);
		}
		else
		{
			go += write(1, &format[i], 1);
		}
		if (go < 0)
			break ;
		i++;
	}
	va_end(args);
	return (go);
}
