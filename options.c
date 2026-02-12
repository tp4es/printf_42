/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:55:24 by tide-oli          #++    #+#             */
/*   Updated: 2026/02/11 16:55:26 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"

void    cases(int c, va_list args, int *i)
{
    if (c == 'c') //single char
        ft_printchar(va_arg(args, int));
    else if (c == 's') //string char
        ft_printstring(va_arg(args, char*));
    else if (c == 'p') //void*
        ft_printpointer(va_arg(args, void*));
    else if (c == 'd' || c == 'i') //digit or decimal int
        ft_printnbr(va_arg(args, int));
    else if (c == 'u') //unsigned decimal int
        ft_printunbr(va_arg(args, unsigned int));
    else if (c == 'x') //hexadecimal lower
        ft_printhex(va_arg(args, unsigned int), "0123456789abcdef");
    else if (c == 'X') //hexadecimal upper
        ft_printhex(va_arg(args, unsigned int), "0123456789ABCDEF");
    else if (c == '%') //% symbol
        ft_printchar('%');
    else
        *i = -1;
}