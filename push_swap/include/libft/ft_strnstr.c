/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:01:14 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 19:01:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	if (*needle == '\0')
		return ((char *)haystack);
	n = ft_strlen(needle);
	while (*haystack != '\0' && n <= len--)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, n) == 0)
			return ((char *)haystack);
		else
			haystack++;
	}
	return (NULL);
}
