/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:54:58 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/05 18:22:13 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_str(char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
    {
        write(1, &(s[i]), 1);
        i++;
    }
    return (i);
}