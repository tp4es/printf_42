/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:07:36 by tide-oli          #+#    #+#             */
/*   Updated: 2026/02/13 20:39:58 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int n, char *base)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_printhex(n / 16, base);
	ft_printchar(base[n % 16]);
	i++;
	return (i);
}
