/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:43:35 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/19 15:23:10 by ilahyani         ###   ########.fr       */
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
