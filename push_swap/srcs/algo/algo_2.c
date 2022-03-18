/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:48:22 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 21:14:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	correct_last_error(t_data *d)
{
	int	error;

	error = 0;
	while (1)
	{
		sort_descending_order_big_stack(d->head_a, d, &error);
		if (!error)
			break ;
		else
		{
			is_better_to_go_up_or_down(&d->head_a, d, 'a');
			push(d, &d->head_a, &d->head_b, 'b');
			while (abs(d->head_b->theoric_rank - d->head_a->theoric_rank) != 1
				&& d->head_b->theoric_rank < d->head_a->theoric_rank)
				rotate(&d->head_a, d, 'a');
			push(d, &d->head_b, &d->head_a, 'a');
			swap(&d->head_a, d, 'a');
		}
	}
}

void	put_longest_nb_on_the_top(t_data *d)
{
	search_longest_nb(d->head_a, d);
	if (d->longest_rank != 1)
	{
		if (d->longest_rank == 2)
			swap(&d->head_a, d, 'a');
		if (d->longest_rank <= d->nb_node_a / 2)
		{
			while (d->head_a->theoric_rank != d->longest_theoric_rank)
				rotate(&d->head_a, d, 'a');
		}
		else
			while (d->head_a->theoric_rank != d->longest_theoric_rank)
				r_rotate(&d->head_a, d, 'a');
	}
}
