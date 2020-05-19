/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:32:54 by mjander           #+#    #+#             */
/*   Updated: 2019/06/19 15:18:24 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	if (n != '0')
	{
		i = 0;
		while (i < n)
		{
			s1[i] = 0;
			i++;
		}
	}
}