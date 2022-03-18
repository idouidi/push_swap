/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:33:48 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 19:57:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	update_rotate(t_stack *head, t_data *d, char c)
{
	if (c == 'a')
	{
		d->end_a = head->nb;
		write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		d->end_b = head->nb;
		write(1, "rb\n", 3);
	}
}

void	rotate(t_stack **head, t_data *d, char c)
{
	t_stack	tmp;
	t_stack	*tmp2;

	if ((*head) == NULL)
		return ;
	if ((*head)->next != NULL)
	{
		update_rotate(*head, d, c);
		tmp = *(*head);
		tmp2 = (*head)->next;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = (*head);
		(*head)->next = NULL;
		(*head) = tmp.next;
		update_rank(head);
	}
}

void	update_r_rotate(t_stack *before_last, t_data *d, char c)
{
	if (c == 'a')
	{
		write(1, "rra\n", 4);
		d->end_a = before_last->nb;
	}
	else if (c == 'b')
	{
		write(1, "rrb\n", 4);
		d->end_b = before_last->nb;
	}
}

void	r_rotate(t_stack **head, t_data *d, char c)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if ((*head) == NULL)
		return ;
	if ((*head)->next != NULL)
	{
		tmp = (*head);
		while (tmp->next != NULL)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		update_r_rotate(tmp2, d, c);
		tmp->next = (*head);
		tmp2->next = NULL;
		(*head) = tmp;
		update_rank(head);
	}
}

void	d_r_rotate(t_stack **head_a, t_stack **head_b, t_data *d)
{
	r_rotate(head_a, d, 'd');
	r_rotate(head_b, d, 'd');
	write(1, "rrr\n", 4);
}
