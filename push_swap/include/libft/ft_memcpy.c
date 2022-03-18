/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:57:27 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 18:57:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char	*src;

	i = 0;
	dest = (unsigned char *)str1;
	src = (unsigned const char *)str2;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
