/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:51:26 by tide-oli          #++    #+#             */
/*   Updated: 2026/02/11 14:51:31 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    int i;

    i = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            cases(format[i], args);
        }
        else
            ft_printchar(format[i]);
        i++;
    }
    va_end(args);
}