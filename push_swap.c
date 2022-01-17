/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:03:02 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/17 17:58:28 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *a, int a_top)
{
	while (a_top > 0 && a[a_top] <= a[a_top - 1])
		a_top--;
	if (!a_top)
		return (1);
	return (0);
}

void	sort_a(int *a, int a_top, int *b, int b_top)
{
	if (a_top == 2)
		three_sort(a, a_top);
	else if (a_top > 2 && a_top < 10)
		ten_sort(a, &a_top, b, &b_top);
	else if (a_top >= 10 && a_top <= 100)
		dozen_sort(a, b, &a_top, &b_top);
	else
		hundred_sort(a, b, &a_top, &b_top);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*a;
	int	*b;
	int	a_top;
	int	b_top;

	if (argc == 1)
		return (0);
	a = malloc (sizeof(int) * argc - 1);
	b = malloc (sizeof(int) * argc - 1);
	if (!a || !b)
		return (0);
	a_top = argc - 2;
	b_top = -1;
	argc--;
	i = 0;
	while (i <= a_top)
		a[i++] = ft_atoi(argv[argc--]);
	/* Need an error msg if input ain't int!!
	ft_printf("------------ unsorted a --------------\n");
	for (i = a_top; i >= 0; i--)
	ft_printf("a[%d] = %d\n", i, a[i]);
	ft_printf("------------ sorting a ---------------\n"); */
	if (!is_sorted(a, a_top))
		sort_a(a, a_top, b, b_top);
	/* ft_printf("------------ sorted a ----------------\n");
	for (i = a_top; i >= 0; i--)
	ft_printf("a[%d] = %d\n", i, a[i]);*/
	if (is_sorted(a, a_top))
		ft_printf("-----> OK <-----\n");
	free(b);
	return (0);
}
