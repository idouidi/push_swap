/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:59:22 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 18:59:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == n)
			return ((char *)str + i);
		i++;
	}
	if (n == 0)
		return ((char *)str + i);
	return (0);
}