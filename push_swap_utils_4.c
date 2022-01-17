/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:20:45 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/17 17:31:22 by ilahyani         ###   ########.fr       */
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

void	biggest_to_top(int *b, int *b_top)
{
	int	idx;

	idx = find_biggest(b, b_top);
	if (idx == *b_top)
		return ;
	if (idx < (*b_top) / 2)
	{
		while (idx >= 0)
		{
			rrb(b, *b_top);
			idx--;
		}
	}
	else
	{	
		while (idx < *b_top)
		{
			rb(b, *b_top);
			idx++;
		}
	}
}

void	sort_copy(int *C, int top)
{
	int	x;
	int	tmp;

	while (top > 0)
	{
		x = find_smallest(C, &top);
		tmp = C[top];
		C[top] = C[x];
		C[x] = tmp;
		top--;
	}
}

void	push_to_b(int *A, int *A_top, int *b, int *b_top, int j)
{
	if (j == *A_top)
		pb(A, b, b_top, A_top);
	else if (j < (*A_top) / 2)
	{
		while (j >= 0)
		{
			rra(A, *A_top);
			j--;
		}
		pb(A, b, b_top, A_top);
	}
	else
	{
		while (j < *A_top)
		{
			ra(A, *A_top);
			j++;
		}
		pb(A, b, b_top, A_top);
	}
}

void	push_to_a(int *A, int *A_top, int *b, int *b_top)
{
	int	count;

	if (!is_sorted(A, *A_top))
	{
		if (*A_top > 2)
			ten_sort(A, A_top, b, b_top);
		else
			three_sort(A, *A_top);
	}
	count = *b_top + 1;
	while (count > 0)
	{
		biggest_to_top(b, b_top);
		pa(A, b, b_top, A_top);
		count--;
	}
}
