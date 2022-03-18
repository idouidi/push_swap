/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:00:40 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 19:00:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i) && i < n - 1)
		i++;
	if (n > 0)
		return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
	return (0);
}
