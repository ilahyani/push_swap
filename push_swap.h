/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:09:31 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/17 17:58:40 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	sa(int *a, int a_top);
void	sb(int *b, int b_top);
void	ss(int *a, int a_top, int *b, int b_top);
void	pa(int *a, int *b, int *b_top, int *a_top);
void	pb(int *a, int *b, int *b_top, int *a_top);
void	ra(int *a, int a_top);
void	rb(int *b, int b_top);
void	rr(int *a, int *b, int a_top, int b_top);
void	rra(int *a, int a_top);
void	rrb(int *b, int b_top);
void	rrr(int *a, int *b, int a_top, int b_top);
int		is_sorted(int *a, int a_top);
void	three_sort(int *a, int a_top);
void	dozen_sort(int *a, int *b, int *a_top, int *b_top);
void	hundred_sort(int *a, int *b, int *a_top, int *b_top);
int		find_smallest(int *stack, int *top);
void	smallest_to_top(int *a, int *a_top);
void	ten_sort(int *a, int *a_top, int *b, int *b_top);
int		find_biggest(int *stack, int *top);
void	biggest_to_top(int *b, int *b_top);
int		*find_keynbr(int *a, int a_top);
void	get_keynbr(int *C, int a_top, int *ret);
void	sort_copy(int *C, int top);
void	push_to_b(int *a, int *a_top, int *b, int *b_top, int j);
void	push_to_a(int *a, int *a_top, int *b, int *b_top);

// typedef struct
// {
// 	int	*a;
// 	int	a_top;
// 	int *b;
// 	int b_top;
// } t_stacks;


#endif
