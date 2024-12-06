/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:27:10 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/06 15:49:38 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_hexa(int n, char *base)
{
    int len;

    len = 0;
    if (n > 15)
        len += ft_print_hexa(n / 16, base);
    len += ft_print_char(base[n % 16]);
    return (len);
}
