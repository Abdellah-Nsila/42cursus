/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:46:02 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/23 10:30:16 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	char	*p;
	unsigned char	c;
	size_t	i;

	i = 0;
	p = ptr;
	c = x;
	while (i < n)
		p[i++] = c;
	return (ptr);
}
