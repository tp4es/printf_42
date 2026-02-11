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

void    cases(char *va_arg)
{
    if (*va_arg == 'c') //single char
        ft_printchar(*va_arg);
    else if (c == 's') //string char
        ft_printstring(va_arg);
    else if (c == 'p') //void*
        ;
    else if (c == 'd' || c == 'i') //digit or decimal int
        ;
    else if (c == 'u') //unsigned decimal int
        ;
    else if (c == 'x') //hexadecimal lower
        ;
    else if (c == 'X') //hexadecimal upper
        ;
    else if (c == '%') //% symbol
        ;
}