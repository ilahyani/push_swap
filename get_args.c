/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:58:24 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/20 12:34:09 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (num == -1 || !isdup(stacks->a, num, ref)
		|| num > 2147483647 || num < -2147483648)
	{
		write(2, "Error\n", 6);
		free(stacks->a);
		free(stacks->b);
		return (1);
	}
	return (0);
}

int	single_arg(char **argv, t_stack *stacks, int *a_top)
{
	long long	num;
	char		**args;
	int			i;
	int			j;

	i = 0;
	args = ft_split(argv[1], ' ');
	while (args[i])
		i++;
	stacks->a = (int *) malloc (sizeof(int) * i);
	stacks->b = (int *) malloc (sizeof(int) * i);
	*a_top = i - 1;
	j = *a_top;
	i = 0;
	while (args[i])
	{
		num = ft_atoi(args[i]);
		if (error_catch(stacks, num, i++))
			return (0);
		stacks->a[j--] = num;
	}
	return (1);
}

int	multiple_args(int argc, char **argv, t_stack *stacks, int *a_top)
{
	long long	num;
	int			i;

	*a_top = argc - 2;
	stacks->a = (int *) malloc (sizeof(int) * (argc - 1));
	stacks->b = (int *) malloc (sizeof(int) * (argc - 1));
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

int	fill_stack(int argc, char **argv, t_stack *stacks, int *a_top)
{
	if (argc == 2)
	{
		if (!single_arg(argv, stacks, a_top))
			return (0);
	}
	else
		if (!multiple_args(argc, argv, stacks, a_top))
			return (0);
	return (1);
}
