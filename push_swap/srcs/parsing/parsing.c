/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:58:18 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 19:59:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	isnt_digit(char *s)
{
	int	i;

	i = 0;
	if (!ft_strcmp("-", s) || !ft_strcmp("", s))
		return (1);
	else if (s[0] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_integer(char **s)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		nb = ft_atoi(s[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (0);
		i += 1;
	}
	return (1);
}

int	check_error(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (isnt_digit(s[i]))
			return (-1);
		j = i + 1;
		while (s[j])
		{
			if (!ft_strcmp(s[j], s[i]))
				return (-1);
			j += 1;
		}
		i += 1;
	}
	if (!is_integer(s))
		return (-1);
	return (0);
}
