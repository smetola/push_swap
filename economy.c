/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   economy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:08:49 by sanmetol          #+#    #+#             */
/*   Updated: 2024/07/30 16:40:57 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_node(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target_node;
	long	min_high;

	while (b)
	{
		min_high = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->n > b->n
				&& current_a->n < min_high)
			{
				min_high = current_a->n;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == min_high)
			b->target = find_smallest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	node_position(t_node *stack)
{
	int	i;
	int	center;

	i = 0;
	if (stack == NULL)
		return ;
	center = stack_size(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= center)
			stack->before_mid = true;
		else
			stack->before_mid = false;
		stack = stack->next;
		++i;
	}
}

void	node_price(t_node *a, t_node *b)
{
	int	a_size;
	int	b_size;

	a_size = stack_size(a);
	b_size = stack_size(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->before_mid))
			b->push_price = b_size - (b->current_position);
		if (b->target->before_mid)
			b->push_price += b->target->current_position;
		else
			b->push_price += a_size - (b->target->current_position);
		b = b->next;
	}
}

void	cheapest_node(t_node *b)
{
	t_node		*best_match_node;
	long		best_match_value;

	if (b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	init_nodes(t_node *a, t_node *b)
{
	target_node(a, b);
	node_position(a);
	node_position(b);
	node_price(a, b);
	cheapest_node(b);
}
