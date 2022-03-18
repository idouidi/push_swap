/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:00:52 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 19:00:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*newstr;

	i = 0;
	if (n > ft_strlen(str))
		n = ft_strlen(str);
	newstr = (char *)malloc(sizeof(char) *(n + 1));
	if (newstr == NULL)
		return (NULL);
	while (i < n)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
