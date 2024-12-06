/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:47:20 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/06 16:09:00 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	handle_format(char format, va_list ap)
{
	if (format == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(ap, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(ap, unsigned long)));
	else if (format == 'd')
		return (ft_print_nbr(va_arg(ap, int)));
	else if (format == 'i')
		return (ft_print_nbr(va_arg(ap, int)));
	else if (format == 'u')
		return (ft_print_unsigned_nbr(va_arg(ap, unsigned int)));
	else if (format == 'x')
		return (ft_print_hexa(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_print_hexa(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else
		return (ft_print_char(format));
}

int ft_printf(const char *s, ...)
{
	va_list ap;
	size_t  i;
	int		len;
	
	if (!s)
		return (-1);
	i = 0;
	len = 0;
	va_start(ap, s);
	ft_print_str((char *)s);
	while (s[i])
	{
		if (s[i] == '%' && s[i+1])
		{	
			len += handle_format(s[i], ap);
			i++;
		}
		else
		{	
			ft_print_char(s[i]);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
