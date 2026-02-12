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

int	ft_printnumbers(int n)
{
	long	number;
	char	str;
	int		i;

	i = 0;
	number = n;
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
		i++;
	}
	if (number > 9)
	{
		ft_printnumbers(number / 10);
		i++;
	}
	str = (number % 10) + '0';
	write(1, &str, 1);
	return ((i + 1));
}
