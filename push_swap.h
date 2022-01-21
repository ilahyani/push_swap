/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:09:31 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/21 05:43:49 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
}	t_stack;

void	sa(t_stack *stacks, int *a_top);
void	sb(t_stack *stacks, int *b_top);
void	ss(t_stack *stacks, int *a_top, int *b_top);
void	pa(t_stack *stacks, int *a_top, int *b_top);
void	pb(t_stack *stacks, int *a_top, int *b_top);
void	ra(t_stack *stacks, int a_top);
void	rb(t_stack *stacksint, int b_top);
void	rr(t_stack *stacks, int a_top, int b_top);
void	rra(t_stack *stacks, int a_top);
void	rrb(t_stack *stacks, int b_top);
void	rrr(t_stack *stacks, int a_top, int b_top);
int		get_args(int argc, char **argv, t_stack *stacks, int *a_top);
int		fill_stack(int argc, char **argv, t_stack *stacks, int *a_top);
void	free_args(char **args);
int		error_catch(t_stack *stacks, long long num, int ref);
void	sort_a(t_stack *stacks, int *a_top, int *b_top);
int		is_sorted(t_stack *stacks, int a_top);
int		isdup(t_stack *stacks, long long num, int ref);
void	three_sort(t_stack *stacks, int *a_top);
void	dozen_sort(t_stack *stacks, int *a_top, int *b_top);
void	hundred_sort(t_stack *stacks, int *a_top, int *b_top);
int		find_smallest(int *stack, int top);
void	smallest_to_top(t_stack *stacks, int *a_top);
void	ten_sort(t_stack *stacks, int *a_top, int *b_top);
int		find_biggest(int *stack, int *top);
void	biggest_to_top(t_stack *stacks, int *b_top);
int		*find_keynbr(int *stack, int top);
void	get_keynbr(int *stack, int top, int *ret);
void	sort_copy(int *stack, int top);
void	push_to_b(t_stack *stacks, int *a_top, int *b_top, int j);
void	push_to_a(t_stack *stacks, int *a_top, int *b_top);

#endif
