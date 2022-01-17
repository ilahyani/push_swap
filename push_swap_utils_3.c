/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:09:58 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/17 17:30:49 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(int *stack, int *top)
{
	int	i;
	int	idx;

	i = 0;
	idx = 1;
	while (i <= *top)
	{
		if (stack[idx] > stack[i])
			idx = i;
		i++;
	}
	return (idx);
}

void	smallest_to_top(int *a, int *a_top)
{
	int	idx;

	idx = find_smallest(a, a_top);
	if (idx == *a_top)
		return ;
	if (idx < (*a_top) / 2)
	{
		while (idx >= 0)
		{
			rra(a, *a_top);
			idx--;
		}
	}
	else
	{	
		while (idx < *a_top)
		{
			ra(a, *a_top);
			idx++;
		}
	}
}

void	get_keynbr(int *c, int a_top, int *ret)
{
	int	i;

	i = 1;
	if (a_top <= 100)
	{
		while (i < 5)
		{
			ret[i] = c[a_top - (a_top / 4) * i];
			i++;
		}
	}
	else
	{
		while (i < 9)
		{
			ret[i] = c[a_top - (a_top / 8) * i];
			i++;
		}
	}
}

int	*find_keynbr(int *a, int a_top)
{
	int	*c;
	int	i;
	int	*ret;

	c = malloc(sizeof(int) * (a_top + 1));
	if (a_top <= 100)
		ret = malloc(sizeof(int) * 4);
	else
		ret = malloc(sizeof(int) * 8);
	if (!c || !ret)
		return (0);
	i = 0;
	while (i <= a_top)
	{
		c[i] = a[i];
		i++;
	}
	sort_copy(c, a_top);
	get_keynbr(c, a_top, ret);
	free (c);
	return (ret);
}
