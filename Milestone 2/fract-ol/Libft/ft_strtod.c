/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:32:57 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/05 17:33:38 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	ft_get_sign(const char *nptr, int *i)
{
	int	sign;

	sign = 1;
	while (nptr[*i] && ft_isspace(nptr[*i]))
		(*i)++;
	if (nptr[*i] == '+' || nptr[*i] == '-')
	{	
		if (nptr[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static double	ft_get_integer_part(const char *nptr, int *i)
{
	double	int_part = 0.0;

	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		int_part = (int_part * 10.0) + (nptr[*i] - '0');
		(*i)++;
	}
	return (int_part);
}

static double	ft_get_decimal_part(const char *nptr, int *i)
{
	double	decimal_part = 0.0;
	double	divisor = 1.0;

	if (nptr[*i] == '.')
	{	
		(*i)++;
		while (nptr[*i] >= '0' && nptr[*i] <= '9')
		{
			decimal_part = (decimal_part * 10.0) + (nptr[*i] - '0');
			divisor *= 10.0;
			(*i)++;
		}
	}
	return (decimal_part / divisor);
}

double	ft_strtod(const char *nptr, char **endptr)
{
	int		i = 0;
	int		sign;
	double	int_part;
	double	decimal_part;
	
	sign = ft_get_sign(nptr, &i);
	int_part = ft_get_integer_part(nptr, &i);
	decimal_part = ft_get_decimal_part(nptr, &i);

	if (endptr)
		*endptr = (char *)(nptr + i);

	return ((int_part + decimal_part) * sign);
}
