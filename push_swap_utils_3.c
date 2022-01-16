/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:09:58 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/16 20:10:00 by ilahyani         ###   ########.fr       */
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

void	biggest_to_top(int *B, int *B_top)
{
	int	idx;

	idx = find_biggest(B, B_top);
	if (idx == *B_top)
		return ;
	if (idx < (*B_top) / 2)
	{
		while (idx >= 0)
		{
			rrb(B, *B_top);
			idx--;
		}
	}
	else
	{	
		while (idx < *B_top)
		{
			rb(B, *B_top);
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

int	*find_keynbr(int *A, int A_top)
{
	int *C;
	int	i;
	int *ret;

	C = malloc(sizeof(int) * (A_top + 1));
	ret = malloc(sizeof(int) * 4);
	if (!C || !ret)
		return (0);								//what then?
	i = 0;
	while (i <= A_top)
	{
		C[i] = A[i];
		i++;
	}
	sort_copy(C, A_top);
	i = 1;
	while (i < 5)
	{
		ret[i] = C[A_top - (A_top/4) * i];
		i++;
	}
	free (C);
	return (ret);
}

void	push_to_b(int *A, int *A_top, int *B, int *B_top, int j)
{
	if (j == *A_top)
		pb(A, B, B_top, A_top);
	else if (j < (*A_top) / 2)
	{
		while (j >= 0)
		{
			rra(A, *A_top);
			j--;
		}
		pb(A, B, B_top, A_top);
	}
	else
	{
		while (j < *A_top)
		{
			ra(A, *A_top);
			j++;
		}
		pb(A, B, B_top, A_top);
	}
}

void	push_to_a(int *A, int *A_top, int *B, int *B_top)
{
	int	count;

	if (!isSorted(A, *A_top))
	{
		if (*A_top > 2)
			ten_sort(A, A_top, B, B_top);
		else
			three_sort(A, *A_top);
	}
	count = *B_top + 1;
	while (count > 0)
	{
		biggest_to_top(B, B_top);
		pa(A, B, B_top, A_top);
		count--;
	}
}

void	dozen_sort(int *A, int *B, int *A_top, int *B_top)
{
	int *key_nbr;
	int	i;
	int	j;
	int	k;
	
	key_nbr = find_keynbr(A, *A_top);
	k = 1;
	while (k < 5)
	{
		i = *A_top;
		while (i >= 0)
		{
			j = i; 
			if (A[j] <= key_nbr[k])
			{
				push_to_b(A, A_top, B, B_top,j);	
				i = (*A_top) + 1;
			}
			i--;
		}
		k++;
	}
	free(key_nbr);
	push_to_a(A, A_top, B, B_top);
}
