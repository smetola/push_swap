/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:08:54 by sanmetol          #+#    #+#             */
/*   Updated: 2024/10/02 12:38:40 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_node **a, t_node **b, t_node *cheap_node, bool rev)
{
	if (!rev)
		while (*a != cheap_node->target && *b != cheap_node)
			rr(a, b, true);
	else
		while (*a != cheap_node->target && *b != cheap_node)
			rrr(a, b, true);
	node_position(*a);
	node_position(*b);
}

void	finish_rotation(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->before_mid)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->before_mid)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

static void	move_nodes(t_node **a, t_node **b)
{
	t_node	*cheap_node;

	cheap_node = return_cheapest(*b);
	if (cheap_node->before_mid && cheap_node->target->before_mid)
		rotate_both(a, b, cheap_node, false);
	else if (!(cheap_node->before_mid) && !(cheap_node->target->before_mid))
		rotate_both(a, b, cheap_node, true);
	finish_rotation(b, cheap_node, 'b');
	finish_rotation(a, cheap_node->target, 'a');
	pa(a, b, true);
}

static void	pushb_by_median(t_node **a, t_node **b, int a_size)
{
	int		*values;
	int		median;
	int		i;
	t_node	*tmp_a;

	i = 0;
	tmp_a = *a;
	values = malloc(a_size * sizeof(int));
	if (!values)
		return ;
	while (tmp_a)
	{
		values[i++] = tmp_a->n;
		tmp_a = tmp_a->next;
	}
	sort(values, a_size);
	median = values[a_size / 2];
	while (a_size-- > 3)
	{
		pb(b, a, true);
		if ((*b)->n >= median)
			rb(b, true);
	}
	free(values);
}

void	push_swap(t_node **a, t_node **b)
{
	t_node	*smallest;
	int		a_size;

	a_size = stack_size(*a);
	if (a_size == 5)
		sort_five(a, b);
	else
		pushb_by_median(a, b, a_size);
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	node_position(*a);
	smallest = find_smallest(*a);
	if (smallest->before_mid)
		while (*a != smallest)
			ra(a, true);
	else
		while (*a != smallest)
			rra(a, true);
}
