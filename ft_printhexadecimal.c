/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexadecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:07:36 by tide-oli          #++    #+#             */
/*   Updated: 2026/02/11 17:07:39 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"

void ft_printhex(unsigned int n, char *base)
{
    if (n >= 16)
        ft_printhex(n / 16, base);
    ft_printchar(base[n % 16]); 
}