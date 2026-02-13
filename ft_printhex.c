/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:07:36 by tide-oli          #+#    #+#             */
/*   Updated: 2026/02/12 23:34:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int n, char *base)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i = ft_printhex(n / 16, base);
	}
	ft_printchar(base[n % 16]);
	return (i + 1);
}
