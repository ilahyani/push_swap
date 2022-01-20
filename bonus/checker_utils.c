/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:11:48 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/20 01:21:10 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "checker.h"

int	is_sorted(t_stack *stacks, int a_top)
{
	while (a_top > 0 && stacks->a[a_top] <= stacks->a[a_top - 1])
		a_top--;
	if (!a_top)
		return (1);
	return (0);
}

int	isdup(int *a, int num, int ref)
{
	int	i;

	if (ref == 0)
		return (1);
	i = 0;
	while (a[i] != num && i < ref)
		i++;
	if (i == ref)
		return (1);
	return (0);
}

int	error_catch(t_stack *stacks, long long num, int ref)
{
	if (num == -1 || !isdup(stacks->a, num, ref) || num > 2147483647)
	{
		write(2, "Error\n", 6);
		free(stacks->a);
		free(stacks->b);
		return (1);
	}
	return (0);
}
