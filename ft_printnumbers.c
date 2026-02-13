/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:07:17 by tide-oli          #+#    #+#             */
/*   Updated: 2026/02/12 23:52:51 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnumbers(long number)
{
	char	str;
	int		i;

	i = 0;
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
		i++;
	}
	if (number > 9)
	{
		i += ft_printnumbers(number / 10);
	}
	str = (number % 10) + '0';
	ft_printchar(str);
	return (i + 1);
}
