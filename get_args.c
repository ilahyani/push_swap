/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:58:24 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/21 05:43:41 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isdup(t_stack *stacks, long long num, int ref)
{
	int	i;

	i = 0;
	if (ref == 0)
		return (1);
	while (stacks->a[i] != num && i < ref)
		i++;
	if (i == ref)
		return (1);
	return (0);
}

int	error_catch(t_stack *stacks, long long num, int ref)
{
	if (num == -1 || !isdup(stacks, num, ref)
		|| num > 2147483647 || num < -2147483648)
	{
		write(2, "Error\n", 6);
		free(stacks->a);
		free(stacks->b);
		return (1);
	}
	return (0);
}

int	get_args(int argc, char **argv, t_stack *stacks, int *a_top)
{
	long long	num;
	int			i;

	*a_top = argc - 2;
	stacks->a = ft_calloc (sizeof(int), (argc - 1));
	stacks->b = ft_calloc (sizeof(int), (argc - 1));
	argc--;
	i = 0;
	while (i <= *a_top)
	{
		num = ft_atoi(argv[argc--]);
		if (error_catch(stacks, num, i))
			return (0);
		stacks->a[i++] = num;
	}
	return (1);
}
