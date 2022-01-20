/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:13:59 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/19 18:53:44 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include"../push_swap.h"

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
int		is_sorted(t_stack *stacks, int a_top);
int		ft_strcmp(const char *s1, const char *s2);
void	make_moves(t_stack *stacks, t_list *moves, int *a_top, int *b_top);
int		isdup(int *a, int num, int ref);
int		error_catch(t_stack *stacks, int num, int ref);
t_list	*get_moves(void);
void	print_res(t_stack *stacks, int *a_top, int *b_top);
void	ft_exec(t_stack *stacks, void *move, int *a_top, int *b_top);

#endif
