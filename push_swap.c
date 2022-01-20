/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:03:02 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/20 11:46:05 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;
	int		a_top;
	int		b_top;

	if (argc == 1)
		return (0);
	a_top = 0;
	b_top = -1;
	if (!fill_stack(argc, argv, &stacks, &a_top))
		return (0);
	if (!is_sorted(&stacks, a_top))
		sort_a(&stacks, &a_top, &b_top);
	free(stacks.b);
	return (0);
}
