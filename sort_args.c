/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:59:46 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/20 11:59:57 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stacks, int a_top)
{
	while (a_top > 0 && stacks->a[a_top] <= stacks->a[a_top - 1])
		a_top--;
	if (!a_top)
		return (1);
	return (0);
}

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

void	sort_a(t_stack *stacks, int *a_top, int *b_top)
{
	if (*a_top <= 2)
		three_sort(stacks, a_top);
	else if (*a_top > 2 && *a_top < 10)
		ten_sort(stacks, a_top, b_top);
	else if (*a_top >= 10 && *a_top <= 100)
		dozen_sort(stacks, a_top, b_top);
	else
		hundred_sort(stacks, a_top, b_top);
}
