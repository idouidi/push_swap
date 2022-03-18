/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:14:55 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 21:17:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	delete_stack(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*current;

	tmp = head;
	while (tmp)
	{
		current = tmp;
		tmp = tmp->next;
		free (current);
	}
}

void	update_rank(t_stack **head)
{
	t_stack	*tmp;
	int		i;

	tmp = *head;
	i = 1;
	while (tmp)
	{
		tmp->rank = i;
		tmp = tmp->next;
		i += 1;
	}
}

void	implem_node(t_stack **head, int nb, int tr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->next = *head;
		new->nb = nb;
		new->rank = 1;
		new->theoric_rank = tr;
		*head = new;
	}
	update_rank(head);
}

void	delete_node(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	if (tmp)
	{
		*head = tmp->next;
		free (tmp);
	}
	update_rank(head);
}

void	count_node(t_data *d, char c)
{
	if (c == 'a')
	{
		d->nb_node_a += 1;
		d->nb_node_b -= 1;
	}
	else if (c == 'b')
	{
		d->nb_node_a -= 1;
		d->nb_node_b += 1;
	}
}
