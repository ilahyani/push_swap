/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:09:52 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/17 17:49:44 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(int *a, int a_top)
{
	if (a_top == 1 && a[1] > a[0])
		sa(a, a_top);
	else if (a[0] >= a[1] && a[0] >= a[2])
		sa(a, a_top);
	else if (a[1] >= a[0] && a[1] >= a[2])
	{
		if (a[0] <= a[2])
			rra(a, a_top);
		else
		{
			rra(a, a_top);
			sa(a, a_top);
		}
	}
	else if (a[2] >= a[0] && a[2] >= a[1])
	{
		if (a[1] >= a[0])
		{
			sa(a, a_top);
			rra(a, a_top);
		}
		else
			ra(a, a_top);
	}
}	

void	ten_sort(int *a, int *a_top, int *b, int *b_top)
{
	int	count;
	int	i;

	count = *a_top + 1;
	i = count;
	while (count > 3)
	{
		if (is_sorted(a, *a_top))
			break ;
		smallest_to_top(a, a_top);
		pb(a, b, b_top, a_top);
		count--;
	}
	if (!is_sorted(a, *a_top))
		three_sort(a, *a_top);
	while (count < i)
	{
		pa(a, b, b_top, a_top);
		count++;
	}
}

void	dozen_sort(int *a, int *b, int *a_top, int *b_top)
{
	int	*key_nbr;
	int	i;
	int	j;
	int	k;

	key_nbr = find_keynbr(a, *a_top);
	k = 1;
	while (k < 5)
	{
		i = *a_top;
		while (i >= 0)
		{
			j = i;
			if (a[j] <= key_nbr[k])
			{
				push_to_b(a, a_top, b, b_top, j);
				i = (*a_top) + 1;
			}
			i--;
		}
		k++;
	}
	free(key_nbr);
	push_to_a(a, a_top, b, b_top);
}

void	hundred_sort(int *a, int *b, int *a_top, int *b_top)
{
	int	*key_nbr;
	int	i;
	int	j;
	int	k;

	key_nbr = find_keynbr(a, *a_top);
	k = 1;
	while (k < 9)
	{
		i = *a_top;
		while (i >= 0)
		{
			j = i;
			if (a[j] <= key_nbr[k])
			{
				push_to_b(a, a_top, b, b_top, j);
				i = (*a_top) + 1;
			}
			i--;
		}
		k++;
	}
	free(key_nbr);
	push_to_a(a, a_top, b, b_top);
}
