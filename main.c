/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:51:01 by tide-oli          #++    #+#             */
/*   Updated: 2026/02/12 17:00:44 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	char	c;
	char	*str;

	i = 1000;
	c = 'c';
	str = "sdad";
	printf("Test Original: %c\n", c);
	ft_printf("Test ft: %c\n", c);
	return (0);
}
