/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:11:21 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 20:03:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push_swap(char *av[], int ac)
{
	t_data	d;

	init_var(&d, ac);
	if (check_error(av) == -1)
		return (-1);
	init_stack(av, &d);
	get_theoric_rank(&d);
	run_push_swap(&d);
	delete_stack(d.head_a);
	delete_stack(d.head_b);
	return (0);
}

int	main(int ac, char *av[])
{
	if (ac <= 2)
	{
		if (ac == 2 && check_error(&av[1]) == -1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		return (0);
	}
	if (push_swap(&av[1], ac) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
