/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:09:47 by sanmetol          #+#    #+#             */
/*   Updated: 2024/10/02 16:10:08 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->n > stack->next->n)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_node	*find_biggest(t_node *stack)
{
	int		biggest;
	t_node	*biggest_node;

	if (stack == NULL)
		return (NULL);
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->n > biggest)
		{
			biggest = stack->n;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

void	sort_three(t_node **a)
{
	t_node	*big_node;

	big_node = find_biggest(*a);
	if (*a == big_node)
		ra (a, true);
	else if ((*a)->next == big_node)
		rra (a, true);
	if ((*a)->n > (*a)->next->n)
		sa (a, true);
}

void	sort_five(t_node **a, t_node **b)
{
	while (stack_size(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, true);
	}
}

void	sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	swapped;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		swapped = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}
