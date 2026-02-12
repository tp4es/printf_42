/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:53:15 by tide-oli          #++    #+#             */
/*   Updated: 2026/02/11 14:53:17 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	options(int c, va_list args);
int	ft_printchar(int c);
int	ft_printstring(char *str);
int	ft_printhex(unsigned int n, char *base);
int	ft_printvoid(void *);
#endif