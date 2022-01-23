/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:57:23 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/21 05:57:13 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hundred_sort(t_stack *stacks, int *a_top, int *b_top)
{
	int	*key_nbr;
	int	i;
	int	k;

	key_nbr = find_keynbr(stacks->a, *a_top);
	k = 0;
	while (k < 8)
	{
		i = *a_top;
		while (i >= 0)
		{
			if (stacks->a[i] <= key_nbr[k])
			{
				push_to_b(stacks, a_top, b_top, i);
				i = (*a_top) + 1;
			}
			i--;
		}
		k++;
	}
	free(key_nbr);
	push_to_a(stacks, a_top, b_top);
}
