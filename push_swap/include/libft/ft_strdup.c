/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:59:50 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 18:59:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*newstr;

	i = 0;
	newstr = NULL;
	if (str == NULL)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (newstr == NULL)
		return (NULL);
	while (i < ft_strlen(str))
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
