/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:00:33 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 19:00:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*stock;
	unsigned int	i;

	if (!s)
		return (NULL);
	stock = ft_strdup(s);
	if (stock == NULL)
		return (NULL);
	i = 0;
	while (stock[i])
	{
		stock[i] = f(i, stock[i]);
		i++;
	}
	return (stock);
}
