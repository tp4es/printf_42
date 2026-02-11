/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:07:17 by tide-oli          #++    #+#             */
/*   Updated: 2026/02/11 17:07:20 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"

void    ft_printnumbers(int i)
{
    long    number;
    char    str;

    number = i;
    if (number < 0)
    {
        write(1, "-", 1);
        number = -number;
    }
    if (number > 9)
        ft_printnumbers(number / 10);
    str = (number % 10) + '0';
    write(1, &str, 1);
}