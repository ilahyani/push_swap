/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:03:02 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/06 11:04:31 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h> 

//This gotta be on a different file

void	sa(int *A)
{
	int	tmp;

	tmp = A[0];
	A[0] = A[1];
	A[1] = tmp;
}

void	sb(int *B)
{
	int	tmp;

	tmp = B[0];
	B[0] = B[1];
	B[1] = tmp;
}

void	pa(int *A, int *B)
{}
void	pb(int *B, int *A)
{}

//all the way down here

int	isSorted(int *A, int c)
{
	int	i;
	
	i = 0;
	while (i < c && A[i] <= A[i + 1])
		i++;
	if (i == c)
		return (1);
	return (0);
}

void	sort_three(int *A)
{
	if (A[0] > A[1] && A[0] < A[2])
		//ra;
	else if (A[1] > A[0] && A[1] > A[2])
	{
		if (A[0] < A[2])
			//rra
			//sa
		else
			//rra
	}
	else if (A[0] > A[1] && A[0] > A[2])
	{
		if (A[1] > A[2])
			//sa
			//rra
		else
			//ra
	}
}	

void	smallest_to_top(int *A, int count)
{
	int	i;
	int	idx;

	i = 1;
	idx = 0;
	while (i < count)
	{
		if (A[idx] > A[i])
			idx = i;
		i++;
	}
	ft_printf("A[%d] = %d\n", idx, A[idx]);
	if (idx > count / 2)	
		while (idx++ <= count)
			// rra(idx, count, A, B);
	else			
		while (idx-- > 0)
			// ra(idx, count, A, B);
}

void	dozen_sort(int *A, int count)
{
	while (count > 0)
	{
		smallest_to_top(A, count--);
		//pb(idx, A, B);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	*A;	//was initialized with NULL
	int	*B;

	if (argc == 1)
		return (0);
	A = malloc (sizeof(int) * argc - 1);
	B = malloc (sizeof(int) * argc - 1);
	if (!A)
		return (0);
	i = argc - 2;
	while (i <= 0)
		A[i] = ft_atoi(argv[i--]);	//Need an error msg if the input ain't int
	if (isSorted(A, argc - 2))
	{
		free(A);
		return (0);
	}
	else if (argc == 4)
		sort_three(A);
	else if (argc >=  10)
		dozen_sort(A, argc - 2);
	free(A);
	return (0);
}
