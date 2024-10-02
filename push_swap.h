/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:09:04 by sanmetol          #+#    #+#             */
/*   Updated: 2024/10/02 16:24:12 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				n;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
	int				current_position;
	int				push_price;
	bool			before_mid;
	bool			cheapest;
}				t_node;

char	*join_args(int argc, char **argv);
void	free_matrix(char **argv);
void	free_error(t_node **a, char **argv);
void	free_stack(t_node **stack);
int		error_syntax(char *str_nbr);
int		error_repetition(t_node *a, int nbr);
char	**ft_split(char *str, char sep);
t_node	*find_last_node(t_node *head);
void	stack_init(t_node **a, char **argv);
void	finish_rotation(t_node **stack, t_node *top_node, char stack_name);
void	push_swap(t_node **a, t_node **b);
void	sa(t_node **a, bool print);
void	sb(t_node **b, bool print);
void	ss(t_node **a, t_node **b, bool print);
void	pa(t_node **a, t_node **b, bool print);
void	pb(t_node **b, t_node **a, bool print);
void	ra(t_node **a, bool print);
void	rb(t_node **b, bool print);
void	rr(t_node **a, t_node **b, bool print);
void	rra(t_node **a, bool print);
void	rrb(t_node **b, bool print);
void	rrr(t_node **a, t_node **b, bool print);
bool	stack_sorted(t_node *stack);
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);
void	sort(int *arr, int size);
void	target_node(t_node *a, t_node *b);
void	node_position(t_node *stack);
void	node_price(t_node *a, t_node *b);
void	cheapest_node(t_node *b);
void	init_nodes(t_node *a, t_node *b);
t_node	*find_smallest(t_node *stack);
t_node	*return_cheapest(t_node *stack);
int		stack_size(t_node *stack);
int		all_spaces(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);

#endif