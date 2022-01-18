/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:09:58 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/18 13:44:27 by ilahyani         ###   ########.fr       */
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

void	get_keynbr(int *stack, int top, int *ret)
{
	int	i;

	i = 1;
	if (top <= 100)
	{
		while (i < 5)
		{
			ret[i] = stack[top - (top / 4) * i];
			i++;
		}
	}
	else
	{
		while (i < 9)
		{
			ret[i] = stack[top - (top / 8) * i];
			i++;
		}
	}
}

int	*find_keynbr(int *stack, int top)
{
	int	*c;
	int	i;
	int	*ret;

	c = malloc(sizeof(int) * (top + 1));
	if (top <= 100)
		ret = malloc(sizeof(int) * 4);
	else
		ret = malloc(sizeof(int) * 8);
	if (!c || !ret)
		return (0);
	i = 0;
	while (i <= top)
	{
		c[i] = stack[i];
		i++;
	}
	sort_copy(c, top);
	get_keynbr(c, top, ret);
	free (c);
	return (ret);
}
