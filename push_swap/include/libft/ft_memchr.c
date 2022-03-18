/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:57:05 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 18:57:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*src;

	i = 0;
	src = s;
	while (i < (unsigned char)n)
	{
		if (src[i] == c)
			return ((void *)src + i);
		else
			i++;
	}
	return (NULL);
}
