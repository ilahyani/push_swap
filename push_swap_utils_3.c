/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:20:45 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/19 12:23:24 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(int *stack, int *top)
{
	int	i;
	int	idx;

	i = 0;
	idx = 1;
	while (i <= *top)
	{
		if (stack[idx] < stack[i])
			idx = i;
		i++;
	}
	return (idx);
}

void	biggest_to_top(t_stack *stacks, int *b_top)
{
	int	idx;

	idx = find_biggest(stacks->b, b_top);
	if (idx == *b_top)
		return ;
	if (idx == *b_top - 1)
		sb(stacks, b_top);
	else if (idx < (*b_top) / 2)
	{
		while (idx >= 0)
		{
			rrb(stacks, *b_top);
			idx--;
		}
	}
	else
	{	
		while (idx < *b_top)
		{
			rb(stacks, *b_top);
			idx++;
		}
	}
}

void	sort_copy(int *stack, int top)
{
	int	x;
	int	tmp;

	while (top > 0)
	{
		x = find_smallest(stack, top);
		tmp = stack[top];
		stack[top] = stack[x];
		stack[x] = tmp;
		top--;
	}
}

void	push_to_b(t_stack *stacks, int *a_top, int *b_top, int j)
{
	if (j == *a_top)
		pb(stacks, a_top, b_top);
	else if (j < (*a_top) / 2)
	{
		while (j >= 0)
		{
			rra(stacks, *a_top);
			j--;
		}
		pb(stacks, a_top, b_top);
	}
	else
	{
		while (j < *a_top)
		{
			ra(stacks, *a_top);
			j++;
		}
		pb(stacks, a_top, b_top);
	}
}

void	push_to_a(t_stack *stacks, int *a_top, int *b_top)
{
	int	count;

	if (!is_sorted(stacks, *a_top))
	{
		if (*a_top > 2)
			ten_sort(stacks, a_top, b_top);
		else
			three_sort(stacks, a_top);
	}
	count = *b_top + 1;
	while (count > 0)
	{
		biggest_to_top(stacks, b_top);
		pa(stacks, a_top, b_top);
		count--;
	}
}
