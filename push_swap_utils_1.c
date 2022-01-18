/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:09:52 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/18 13:44:21 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack *stacks, int *a_top)
{
	if (*a_top == 1 && stacks->a[1] > stacks->a[0])
		sa(stacks, a_top);
	else if (stacks->a[0] >= stacks->a[1] && stacks->a[0] >= stacks->a[2])
		sa(stacks, a_top);
	else if (stacks->a[1] >= stacks->a[0] && stacks->a[1] >= stacks->a[2])
	{
		if (stacks->a[0] <= stacks->a[2])
			rra(stacks, *a_top);
		else
		{
			rra(stacks, *a_top);
			sa(stacks, a_top);
		}
	}
	else if (stacks->a[2] >= stacks->a[0] && stacks->a[2] >= stacks->a[1])
	{
		if (stacks->a[1] >= stacks->a[0])
		{
			sa(stacks, a_top);
			rra(stacks, *a_top);
		}
		else
			ra(stacks, *a_top);
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

void	dozen_sort(t_stack *stacks, int *a_top, int *b_top)
{
	int	*key_nbr;
	int	i;
	int	j;
	int	k;

	key_nbr = find_keynbr(stacks->a, *a_top);
	k = 1;
	while (k < 5)
	{
		i = *a_top;
		while (i >= 0)
		{
			j = i;
			if (stacks->a[j] <= key_nbr[k])
			{
				push_to_b(stacks, a_top, b_top, j);
				i = (*a_top) + 1;
			}
			i--;
		}
		k++;
	}
	free(key_nbr);
	push_to_a(stacks, a_top, b_top);
}

void	hundred_sort(t_stack *stacks, int *a_top, int *b_top)
{
	int	*key_nbr;
	int	i;
	int	j;
	int	k;

	key_nbr = find_keynbr(stacks->a, *a_top);
	k = 1;
	while (k < 9)
	{
		i = *a_top;
		while (i >= 0)
		{
			j = i;
			if (stacks->a[j] <= key_nbr[k])
			{
				push_to_b(stacks, a_top, b_top, j);
				i = (*a_top) + 1;
			}
			i--;
		}
		k++;
	}
	free(key_nbr);
	push_to_a(stacks, a_top, b_top);
}
