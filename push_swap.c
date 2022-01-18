/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:03:02 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/18 23:15:35 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	error_check(t_stack *stacks, int num, int ref)
{
	if (num == -1 || !isdup(stacks->a, num, ref) || num > 2147483647)
	{
		ft_printf("Error");
		free (stacks->a);
		free (stacks->b);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stacks;
	int		i;
	int		num;
	int		a_top;
	int		b_top;

	if (argc < 3)
		return (0);
	a_top = argc - 2;
	b_top = -1;
	stacks.a = (int *) malloc (sizeof(int) * (argc - 1));
	stacks.b = (int *) malloc (sizeof(int) * (argc - 1));
	argc--;
	i = 0;
	while (i <= a_top)
	{
		num = ft_atoi(argv[argc--]);
		if (error_check(&stacks, num, i))
			return (0);
		stacks.a[i++] = num;
	}
	if (!is_sorted(&stacks, a_top))
		sort_a(&stacks, &a_top, &b_top);
	// for (i = a_top; i >= 0; i--)
	// 	ft_printf("a[%d] = %d\n", i, stacks.a[i]);
	free(stacks.b);
	return (0);
}
