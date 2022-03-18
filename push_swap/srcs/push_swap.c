/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:38:26 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 20:24:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_var(t_data *d, int ac)
{
	d->head_a = NULL;
	d->head_b = NULL;
	d->end_a = 0;
	d->end_b = 0;
	d->nb_node_a = ac - 1;
	d->nb_node_b = 0;
	d->average = 0;
}

void	init_stack2(t_stack **tmp, t_data *d, int *rank)
{
	*tmp = d->head_a;
	(*tmp)->theoric_rank = -1;
	d->end_a = (*tmp)->nb;
	*rank = 2;
}

void	init_stack(char *av[], t_data *d)
{
	int		i;
	int		rank;
	t_stack	*tmp;
	t_stack	*new;

	implem_node(&d->head_a, ft_atoi(av[0]), -1);
	init_stack2(&tmp, d, &rank);
	i = 1;
	while (av[i])
	{
		new = malloc(sizeof(t_stack));
		if (new)
		{
			new->nb = ft_atoi(av[i]);
			new->rank = rank;
			new->theoric_rank = -1;
			new->next = NULL;
			tmp->next = new;
			tmp = tmp->next;
			if (av[i + 1] == NULL)
				d->end_a = new->nb;
		}
		i += 1;
		rank++;
	}
}

void	next_node_uninitialized(t_stack *head, int *shortest)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->theoric_rank == -1)
		{
			*shortest = tmp->nb;
			return ;
		}
		tmp = tmp->next;
	}
}

void	get_theoric_rank(t_data *d)
{
	int		i;
	t_stack	*tmp;
	int		shortest;

	i = 0;
	tmp = d->head_a;
	while (i < d->nb_node_a)
	{
		next_node_uninitialized(d->head_a, &shortest);
		tmp = d->head_a;
		while (tmp)
		{
			if (shortest > tmp->nb && tmp->theoric_rank == -1)
				shortest = tmp->nb;
			tmp = tmp->next;
		}
		tmp = d->head_a;
		while (tmp->nb != shortest)
			tmp = tmp->next;
		tmp->theoric_rank = ++i;
	}	
}
