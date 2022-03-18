/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:59:43 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 18:59:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_2(char **str)
{
	int		i;
	char	**newstr;

	i = 0;
	newstr = NULL;
	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	newstr = (char **)malloc(sizeof(char *) * i);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		newstr[i] = ft_strdup(str[i]);
		i++;
	}
	newstr[i] = NULL;
	return (newstr);
}
