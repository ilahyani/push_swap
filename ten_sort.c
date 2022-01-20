/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:00:47 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/20 12:01:15 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(int *stack, int top)
{
	int	i;
	int	idx;

	i = 0;
	idx = 1;
	while (i <= top)
	{
		if (stack[idx] > stack[i])
			idx = i;
		i++;
	}
	return (idx);
}

void	smallest_to_top(t_stack *stacks, int *a_top)
{
	int	idx;

	idx = find_smallest(stacks->a, *a_top);
	if (idx == *a_top)
		return ;
	if (idx < (*a_top) / 2)
	{
		while (idx >= 0)
		{
			rra(stacks, *a_top);
			idx--;
		}
	}
	else
	{	
		while (idx < *a_top)
		{
			ra(stacks, *a_top);
			idx++;
		}
	}
}

void	ten_sort(t_stack *stacks, int *a_top, int *b_top)
{
	int	count;
	int	i;

	count = *a_top + 1;
	i = count;
	while (count > 3)
	{
		if (is_sorted(stacks, *a_top))
			break ;
		smallest_to_top(stacks, a_top);
		pb(stacks, a_top, b_top);
		count--;
	}
	if (!is_sorted(stacks, *a_top))
		three_sort(stacks, a_top);
	while (count < i)
	{
		pa(stacks, a_top, b_top);
		count++;
	}
}
