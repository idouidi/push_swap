/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:41:02 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 21:11:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	final_sort_short_stack(t_data *d)
{		
	while (d->nb_node_b)
	{
		if (sort_descending_order(d->head_b) == 1)
		{
			while (d->nb_node_b)
				push(d, &d->head_b, &d->head_a, 'a');
		}
		else if (sort_asceding_order(d->head_b) == 1)
		{
			while (d->nb_node_b)
			{
				r_rotate(&d->head_b, d, 'b');
				push(d, &d->head_b, &d->head_a, 'a');
			}
		}
		else
		{
			search_longest_nb(d->head_b, d);
			is_better_to_go_up_or_down(&d->head_b, d, 'b');
			push(d, &d->head_b, &d->head_a, 'a');
		}
	}
}

void	short_stack(t_data *d)
{		
	while (d->nb_node_a > 3)
	{
		if (sort_asceding_order(d->head_a))
			break ;
		send_nb_under_the_average(d);
	}
	if (d->nb_node_a == 2 && !sort_asceding_order(d->head_a))
		swap(&d->head_a, d, 'a');
	else if (d->nb_node_a == 3 && !sort_asceding_order(d->head_a))
	{
		search_longest_nb(d->head_a, d);
		if (d->longest_rank == 1)
			rotate(&d->head_a, d, 'a');
		else if (d->longest_rank == 2)
			r_rotate(&d->head_a, d, 'a');
		if (d->head_a->nb > d->head_a->next->nb)
			swap(&d->head_a, d, 'a');
	}
	final_sort_short_stack(d);
}

void	big_stack(t_data *d, int *i, t_stack **tmp)
{
	while (*i < 31)
	{
		*tmp = d->head_a;
		while (*tmp)
		{
			if ((*tmp)->theoric_rank & (1 << *i))
			{
				d->current_theoric_rank = (*tmp)->theoric_rank;
				d->current_rank = (*tmp)->rank;
				is_better_to_go_up_or_down(&d->head_a, d, 'a');
				push(d, &d->head_a, &d->head_b, 'b');
				*tmp = d->head_a;
			}
			else
				*tmp = (*tmp)->next;
		}
		while (d->nb_node_b > 1)
		{
			if (d->head_b->theoric_rank == 1)
				rotate(&d->head_b, d, 'b');
			else
				push(d, &d->head_b, &d->head_a, 'a');
		}
		*i += 1;
	}
}

void	run_push_swap(t_data *d)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = d->head_a;
	if (d->nb_node_a < 450)
		short_stack(d);
	else
	{
		big_stack(d, &i, &tmp);
		put_longest_nb_on_the_top(d);
		correct_last_error(d);
		put_longest_nb_on_the_top(d);
		while (d->nb_node_a)
		{
			r_rotate(&d->head_a, d, 'a');
			push(d, &d->head_a, &d->head_b, 'b');
		}
		while (d->nb_node_b)
			push(d, &d->head_b, &d->head_a, 'a');
	}
}
