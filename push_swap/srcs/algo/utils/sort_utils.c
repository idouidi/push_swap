/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:20:36 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 19:23:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	sort_asceding_order(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	sort_descending_order(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next)
	{
		if (tmp->nb < tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_asceding_order_big_stack(t_stack *head, t_data *d, int	*error)
{
	t_stack	*tmp;

	tmp = head;
	*error = 0;
	d->current_rank = tmp->rank;
	d->current_theoric_rank = tmp->theoric_rank;
	search_longest_nb(head, d);
	while (tmp->next)
	{
		if (tmp->theoric_rank > tmp->next->theoric_rank
			&& tmp->next->theoric_rank != d->longest_theoric_rank)
		{
			d->current_theoric_rank = tmp->theoric_rank;
			d->current_rank = tmp->rank;
			*error = 1;
			return ;
		}
		tmp = tmp->next;
	}
}

void	sort_descending_order_big_stack(t_stack *head, t_data *d, int	*error)
{
	t_stack	*tmp;

	tmp = head;
	*error = 0;
	d->current_theoric_rank = tmp->theoric_rank;
	d->current_rank = tmp->rank;
	search_longest_nb(head, d);
	while (tmp->next)
	{
		if (tmp->theoric_rank < tmp->next->theoric_rank
			&& tmp->next->theoric_rank != d->longest_theoric_rank)
		{
			d->current_theoric_rank = tmp->theoric_rank;
			d->current_rank = tmp->rank;
			*error = 1;
			return ;
		}
		tmp = tmp->next;
	}
}
