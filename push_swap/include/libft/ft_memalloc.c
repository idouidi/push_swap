/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:56:16 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 18:56:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memalloc(size_t n)
{
	void	*mem;

	mem = malloc(sizeof(n));
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, n);
	return (mem);
}
