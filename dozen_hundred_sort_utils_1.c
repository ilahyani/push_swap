/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dozen_hundred_sort_utils_1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:54:25 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/21 02:31:05 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	get_keynbr(int *stack, int top, int *ret)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (top <= 100)
	{
		while (i < 5)
		{
			ret[j++] = stack[top - (top / 4) * i++];
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
