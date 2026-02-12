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

int    cases(char *va_arg)
{
    if (*va_arg == 'c') //single char
        return (ft_printchar(*va_arg, char));
    else if (c == 's') //string char
        return (ft_printstring(va_arg, char*));
    else if (c == 'p') //void*
        return (ft_printvoid(va_arg, void*));
    else if (c == 'd' || c == 'i') //digit or decimal int
        return (ft_printnumbers(va_arg, int));
    else if (c == 'u') //unsigned decimal int
        return (ft_printnumbers(va_arg, unsigned int));
    else if (c == 'x') //hexadecimal lower
        return (ft_printhexadecimal(va_arg, unsigned int, "0123456789abcdef"));
    else if (c == 'X') //hexadecimal upper
        return (ft_printhexadecimal(va_arg, unsigned int, "0123456789ABCDEF"));
    else if (c == '%') //% symbol
        return (ft_printchar('%'));
    else
        return(-2);
}