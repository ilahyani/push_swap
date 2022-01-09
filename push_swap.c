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

#include "libft/libft.h"
#include <stdio.h> 

//This gotta be on a utils file

void	sa(int *A, int *A_top)
{
	int	tmp;

	tmp = A[A_top - 1];
	A[A_top - 1] = A[A_top];
	A[A_top] = tmp;
	ft_printf("sa\n");
}

void	sb(int *B, int *B_top)
{
	int	tmp;

	tmp = A[B_top - 1];
	A[B_top - 1] = A[B_top];
	A[B_top] = tmp;
	ft_printf("sb\n");
}

void	ss(int *A, int *A_top, int *B, int B_top)
{
	sa(A, A_top);
	sb(B, B_top);
	ft_printf("ss\n");
}

// Handle the stack overflow/underflow case (if (B_top++ > B_size) || if (B_top-- < 0) then exit(1))
void	pa(int *A, int *B, int *B_top, int *A_top) 
{
	B_top++;
	B[B_top] = A[A_top];
	A_top--;
	ft_printf("pa\n");
}

void	pb(int *A, int *B, int *B_top, int *A_top)
{
	A_top++;
	A[A_top] = B[B_top];
	B_top--;
	ft_printf("pb\n");
}

void	ra(int *A, int *A_top)
{
}

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
		//ra();
	else if (A[1] > A[0] && A[1] > A[2])
	{
		if (A[0] < A[2])
			//rra();
			//sa();
		else
			//rra();
	}
	else if (A[0] > A[1] && A[0] > A[2])
	{
		if (A[1] > A[2])
			//sa();
			//rra();
		else
			//ra();
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
//	ft_printf("A[%d] = %d\n", idx, A[idx]);
	if (idx > count / 2)	
		while (idx++ <= count)
			// rra();
	else			
		while (idx-- > 0)
			// ra();
}

void	dozen_sort(int *A, int count)
{
	while (count > 0)
	{
		smallest_to_top(A, count--);
		//pb();
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	*A;	//was initialized with NULL
	int	*B;
	int	A_top;
	int	B_top;

	if (argc == 1)
		return (0);
	A = malloc (sizeof(int) * argc - 1);
	B = malloc (sizeof(int) * argc - 1);
	if (!A)
		return (0);
	i = 1;
	while (i < argc - 1)
	{
		A[i - 1] = ft_atoi(argv[i]);	//Need an error msg if the input ain't int
		i++;
	}
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
