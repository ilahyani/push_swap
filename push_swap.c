/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:03:02 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/09 23:50:12 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isSorted(int *A, int A_top)
{
	while (A_top > 0 && A[A_top] <= A[A_top - 1])
		A_top--;
	if (!A_top)
		return (1);
	return (0);
}

void	sort_A(int *A, int A_top, int *B, int B_top)
{
	if (A_top == 2)
		three_sort(A, A_top);
	else if (A_top > 2 && A_top <  10)
		ten_sort(A, &A_top, B, &B_top);
	else if (A_top >= 10 && A_top <= 100)
		dozen_sort(A, B, &A_top, &B_top);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*A;
	int	*B;
	int	A_top;
	int	B_top;

	if (argc == 1)
		return (0);
	A = malloc (sizeof(int) * argc - 1);
	B = malloc (sizeof(int) * argc - 1);
	if (!A || !B)
		return (0);
	A_top = argc - 2;
	B_top = -1;
	argc--;
	i = 0;
	while (i <= A_top)
		A[i++] = ft_atoi(argv[argc--]);		// Need an error msg if input ain't int!!
	// ft_printf("------------ unsorted A --------------\n");
	// for (i = A_top; i >= 0; i--)
	// 	ft_printf("A[%d] = %d\n", i, A[i]);
	// ft_printf("------------ sorting A ---------------\n");
	if (!isSorted(A, A_top))
		sort_A(A, A_top, B, B_top);
	// ft_printf("------------ sorted A ----------------\n");
	// for (i = A_top; i >= 0; i--)
	// 	ft_printf("A[%d] = %d\n", i, A[i]);
	if (isSorted(A, A_top))
		ft_printf("-----> OK <-----\n");
	free(B);
	return (0);
}
