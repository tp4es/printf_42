/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:53:15 by tide-oli          #+#    #+#             */
/*   Updated: 2026/02/13 20:20:50 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	options(int c, va_list args);
int	ft_printstring(char *str);
int	ft_printvoid(void *v);
int	ft_printchar(int c);
int	ft_signednumber(int n);
int	ft_printnumbers(unsigned int n);
int	ft_printhex(unsigned long n, char *base);
#endif