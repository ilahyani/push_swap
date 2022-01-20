/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:23:14 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/19 15:46:04 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
}

void	rrr(t_stack *stacks, int a_top, int b_top)
{
	rra(stacks, a_top);
	rrb(stacks, b_top);
}
