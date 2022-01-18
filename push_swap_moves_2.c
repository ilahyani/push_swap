/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:43:35 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/18 13:43:57 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stacks, int a_top)
{
	int	tmp;

	while (a_top > 0)
	{
		tmp = stacks->a[a_top - 1];
		stacks->a[a_top - 1] = stacks->a[a_top];
		stacks->a[a_top] = tmp;
		(a_top)--;
	}	
	ft_printf("ra\n");
}

void	rb(t_stack *stacks, int b_top)
{
	int	tmp;

	while (b_top > 0)
	{
		tmp = stacks->b[b_top - 1];
		stacks->b[b_top - 1] = stacks->b[b_top];
		stacks->b[b_top] = tmp;
		(b_top)--;
	}
	ft_printf("rb\n");
}

void	rr(t_stack *stacks, int a_top, int b_top)
{
	ra(stacks, a_top);
	rb(stacks, b_top);
	ft_printf("rb\n");
}

void	rra(t_stack *stacks, int a_top)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < a_top)
	{
		tmp = stacks->a[i];
		stacks->a[i] = stacks->a[i + 1];
		stacks->a[i + 1] = tmp;
		i++;
	}
	ft_printf("rra\n");
}

void	rrb(t_stack *stacks, int b_top)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < b_top)
	{
		tmp = stacks->b[i];
		stacks->b[i] = stacks->b[i + 1];
		stacks->b[i + 1] = tmp;
		i++;
	}
	ft_printf("rrb\n");
}

void	rrr(t_stack *stacks, int a_top, int b_top)
{
	rra(stacks, a_top);
	rrb(stacks, b_top);
	ft_printf("rrr\n");
}
