/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:46:39 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 21:17:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int				nb;
	int				rank;
	int				theoric_rank;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	int				nb_node_a;
	int				nb_node_b;
	int				end_a;
	int				end_b;
	int				current_rank;
	int				current_theoric_rank;
	int				longest_rank;
	int				longest_theoric_rank;
	int				average;
	t_stack			*head_a;
	t_stack			*head_b;
}					t_data;

/*
**************		PARSING		************************************************
*/
int					check_error(char **s);
void				init_var(t_data *d, int ac);
void				init_stack(char *av[], t_data *d);
void				get_theoric_rank(t_data *d);
/*
**************		MAIN FUNC	************************************************
*/

int					push_swap(char *av[], int ac);
void				run_push_swap(t_data *d);
/*
**************		MOVES		************************************************
*/

void				push(t_data *d, t_stack **src, t_stack **dst, char c);
void				swap(t_stack **head, t_data *d, char c);
void				d_swap(t_stack **head_a, t_stack **head_b, t_data *d);
void				rotate(t_stack **head, t_data *d, char c);
void				d_rotate(t_stack **head_a, t_stack **head_b, t_data *d);
void				r_rotate(t_stack **head, t_data *d, char c);
void				d_r_rotate(t_stack **head_a, t_stack **head_b, t_data *d);
/*
**************		UTILS		************************************************
*/

/*
*				~	moves	~
*/
void				count_node(t_data *d, char c);
void				update_rank(t_stack **head);
void				implem_node(t_stack **head, int nb, int tr);
void				delete_node(t_stack **head);
void				delete_stack(t_stack *head);
/*
*				~	algo	~
*/
void				search_longest_nb(t_stack *head, t_data *d);
void				put_longest_nb_on_the_top(t_data *d);
void				correct_last_error(t_data *d);
void				current_average(t_data *d, int nb_node, char c);
void				send_nb_under_the_average(t_data *d);
void				is_better_to_go_up_or_down(t_stack **hd, t_data *d, char c);
void				sort_descending_order_big_stack(t_stack *hd, t_data *d,
						int *error);
void				sort_asceding_order_big_stack(t_stack *head, t_data *d,
						int	*error);
int					sort_asceding_order(t_stack *head);
int					sort_descending_order(t_stack *head);
/*
********************************************************************************
*/
#endif
