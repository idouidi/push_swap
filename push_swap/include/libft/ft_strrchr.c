/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:01:20 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 19:01:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int		i;

	i = ft_strlen(str) - 1;
	if (n == 0)
		i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == n)
			return ((char *)str + i);
		i--;
	}
	if (i == -1)
		return ((char *) NULL);
	return (0);
}
