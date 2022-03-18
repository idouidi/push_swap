/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:27:52 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 19:56:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(t_data *d, t_stack **src, t_stack **dst, char c)
{
	if (*src)
	{
		if (c == 'a')
		{
			write(1, "pa\n", 3);
			count_node(d, 'a');
			if (d->nb_node_a == 1)
				d->end_a = (*src)->nb;
		}
		else if (c == 'b')
		{
			write(1, "pb\n", 3);
			count_node(d, 'b');
			if (d->nb_node_b == 1)
				d->end_b = (*src)->nb;
		}
		implem_node(dst, (*src)->nb, (*src)->theoric_rank);
		delete_node(src);
	}
}

void	swap_node(t_stack *head)
{
	t_stack	*stock;
	int		tmp;

	stock = head->next;
	tmp = head->nb;
	head->nb = stock->nb;
	stock->nb = tmp;
	tmp = head->theoric_rank;
	head->theoric_rank = stock->theoric_rank;
	stock->theoric_rank = tmp;
}

void	swap(t_stack **head, t_data *d, char c)
{
	if ((*head) == NULL)
		return ;
	if ((*head)->next != NULL)
	{
		if (c == 'a')
		{
			write(1, "sa\n", 3);
			if (d->nb_node_a == 2)
				d->end_a = (*head)->nb;
		}
		else if (c == 'b')
		{
			write(1, "sb\n", 3);
			if (d->end_b == 2)
				d->end_b = (*head)->nb;
		}
		swap_node(*head);
	}
}

void	d_swap(t_stack **head_a, t_stack **head_b, t_data *d)
{
	swap(head_a, d, 'd');
	swap(head_b, d, 'd');
	write(1, "ss\n", 3);
}

void	d_rotate(t_stack **head_a, t_stack **head_b, t_data *d)
{
	rotate(head_a, d, 'd');
	rotate(head_b, d, 'd');
	write(1, "rr\n", 3);
}
