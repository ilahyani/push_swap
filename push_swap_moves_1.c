/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:09:43 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/18 13:44:02 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stacks, int *a_top)
{
	int	tmp;

	tmp = stacks->a[*a_top - 1];
	stacks->a[*a_top - 1] = stacks->a[*a_top];
	stacks->a[*a_top] = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack *stacks, int *b_top)
{
	int	tmp;

	tmp = stacks->b[*b_top - 1];
	stacks->b[*b_top - 1] = stacks->b[*b_top];
	stacks->b[*b_top] = tmp;
	ft_printf("sb\n");
}

void	ss(t_stack *stacks, int *a_top, int *b_top)
{
	sa(stacks, a_top);
	sb(stacks, b_top);
	ft_printf("ss\n");
}

void	pa(t_stack *stacks, int *a_top, int *b_top)
{
	(*a_top)++;
	stacks->a[*a_top] = stacks->b[*b_top];
	(*b_top)--;
	ft_printf("pa\n");
}

void	pb(t_stack *stacks, int *a_top, int *b_top)
{
	(*b_top)++;
	stacks->b[*b_top] = stacks->a[*a_top];
	(*a_top)--;
	ft_printf("pb\n");
}
