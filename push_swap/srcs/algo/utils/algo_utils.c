/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:17:42 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 19:21:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	search_longest_nb(t_stack *head, t_data *d)
{
	t_stack	*tmp;

	tmp = head;
	d->longest_theoric_rank = tmp->theoric_rank;
	d->longest_rank = tmp->rank;
	while (tmp)
	{
		if (d->longest_theoric_rank < tmp->theoric_rank)
		{
			d->longest_theoric_rank = tmp->theoric_rank;
			d->longest_rank = tmp->rank;
		}
		tmp = tmp->next;
	}
}

void	is_better_to_go_up_or_down(t_stack **head, t_data *d, char c)
{
	int		nb_node;
	int		rank;
	int		theoric_rank;

	if (c == 'a')
	{
		theoric_rank = d->current_theoric_rank;
		rank = d->current_rank;
		nb_node = d->nb_node_a;
	}
	else if (c == 'b')
	{
		theoric_rank = d->longest_theoric_rank;
		rank = d->longest_rank;
		nb_node = d->nb_node_b;
	}
	if (rank <= nb_node / 2)
	{
		while ((*head)->theoric_rank != theoric_rank)
			rotate(head, d, c);
	}
	else
		while ((*head)->theoric_rank != theoric_rank)
			r_rotate(head, d, c);
}

int	there_is_only_value_sup_average(t_data *d, char c)
{
	t_stack	*tmp;

	if (c == 'a')
	{
		tmp = d->head_a;
		while (tmp)
		{
			if (tmp->nb < d->average)
				return (0);
			tmp = tmp->next;
		}
	}
	else if (c == 'b')
	{
		tmp = d->head_b;
		while (tmp)
		{
			if (tmp->nb > d->average)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

void	current_average(t_data *d, int nb_node, char c)
{
	t_stack	*tmp;
	long	sum;

	sum = 0;
	tmp = NULL;
	if (c == 'a')
		tmp = d->head_a;
	else if (c == 'b')
		tmp = d->head_b;
	while (tmp)
	{
		sum += tmp->nb;
		tmp = tmp->next;
	}
	d->average = sum / nb_node;
}

void	send_nb_under_the_average(t_data *d)
{
	current_average(d, d->nb_node_a, 'a');
	while (1)
	{
		if (d->head_a->nb < d->average)
			push(d, &d->head_a, &d->head_b, 'b');
		else if (d->end_a < d->average)
		{
			r_rotate(&d->head_a, d, 'a');
			push(d, &d->head_a, &d->head_b, 'b');
		}
		else
			rotate(&d->head_a, d, 'a');
		if (there_is_only_value_sup_average(d, 'a'))
			break ;
	}
}
