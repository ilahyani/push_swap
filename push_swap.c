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
/////////////////////////////////////////////////////////////////////////////////////////////////
void	sa(int *A, int A_top)
{
	int	tmp;

	tmp = *(A + A_top - 1);
	*(A + A_top - 1) = *(A + A_top);
	*(A + A_top) = tmp;
	ft_printf("sa\n");
}

void	sb(int *B, int B_top)
{
	int	tmp;

	tmp = *(B + B_top - 1);
	*(B + B_top - 1) = *(B + B_top);
	*(B + B_top) = tmp;
	ft_printf("sb\n");
}

void	ss(int *A, int A_top, int *B, int B_top)
{
	sa(A, A_top);
	sb(B, B_top);
	ft_printf("ss\n");
}

void	pa(int *A, int *B, int *B_top, int *A_top) 
{
	(*A_top)++;				// Handle the stack overflow/underflow case (if (B_top++ > B_size) || (B_top-- < 0) then exit(1))
	*(A + *B_top) = *(B + *A_top);
	(*B_top)--;
	ft_printf("pa\n");
}

void	pb(int *A, int *B, int *B_top, int *A_top)
{
	(*B_top)++;
	*(B + *A_top) = *(A + *B_top);
	(*A_top)--;
	ft_printf("pb\n");
}

void	ra(int *A, int A_top)
{
	int tmp;

	while (A_top > 0)
	{
		tmp = *(A + A_top);
		*(A + A_top) = *(A + A_top);
		*(A + A_top) = tmp;
		A_top--;
	}	
	ft_printf("ra\n");
}

void	rb(int *B, int B_top)
{
	int tmp;

	while (B_top > 0)
	{
		tmp = *(B + B_top);
		*(B + B_top) = *(B + B_top);
		*(B+ B_top) = tmp;
		B_top--;
	}
	ft_printf("rb\n");
}

void	rr(int *A, int *B, int A_top, int B_top)
{
	ra(A, A_top);
	rb(B, B_top);
	ft_printf("rb\n");
}

void	rra(int *A, int A_top)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < A_top)
	{
		tmp = *(A + i);
		*(A + i) = *(A + i + 1);
		*(A + i + 1) = tmp;
		i++;
	}
	ft_printf("rra\n");
}

void	rrb(int *B, int B_top)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < B_top)
	{
		tmp = *(B + i);
		*(B + i) = *(B + i + 1);
		*(B + i + 1) = tmp;
		i++;
	}
	ft_printf("rrb\n");
}

void	rrr(int *A, int *B, int A_top, int B_top)
{
	rra(A, A_top);
	rrb(B, B_top);
	ft_printf("rrr\n");
}

int	isSorted(int *A, int A_top)
{
	while (A_top > 0 && A[A_top] <= A[A_top - 1])
		A_top--;
	if (!A_top)
		return (1);
	return (0);
}

void	sort_three(int *A, int A_top)
{
	if (A[0] >= A[1] && A[0] >= A[2])
		sa(A, A_top);
	else if (A[1] >= A[0] && A[1] >= A[2])
	{
		if (A[0] <= A[2])
			rra(A, A_top);
		else
		{
			rra(A, A_top);
			sa(A, A_top);
		}
	}
	else if (A[2] >= A[0] && A[2] >= A[1])
	{
		if (A[1] >= A[0])
		{
			sa(A, A_top);
			rra(A, A_top);
		}
		else
			ra(A, A_top);
	}
}	

void	smallest_to_top(int *A, int A_top)
{
	int	i;
	int	idx;

	i = 1;
	idx = 0;
	while (i < A_top)
	{
		if (A[idx] > A[i])
			idx = i;
		i++;
	}
	ft_printf("smallest A[%d] = %d\n", idx, A[idx]);
	if (idx > A_top / 2)	
		while (idx++ <= A_top)
			rra(A, A_top);
	else			
		while (idx-- > 0)
			ra(A, A_top);
}

void	dozen_sort(int *A, int *A_top, int *B, int *B_top)
{
	int	count;
	int	i;

	count = *A_top;
	i = count;
	while (count > 0)
	{
		smallest_to_top(A, *A_top);
		pb(A, B, B_top, A_top);
		count--;
	}
	while (count++ < i)
		pa(A, B, B_top, A_top);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

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
	if (!A)
		return (0);
	i = 1;
	while (i < argc)
	{
		A[i - 1] = ft_atoi(argv[i]);	//Need an error msg if input ain't int
		i++;
	}
//	for (i = 0; i < argc - 1; i++)
//		ft_printf("A[%d] = %d\n", i, A[i]);
	A_top = argc - 2;
	B_top = -1;
	if (isSorted(A, A_top))
	{
		ft_printf("already sorted");
		free(A);
		free(B);
		return (0);
	}
	else if (argc == 4)
		sort_three(A, A_top);
	else if (argc <=  10)
		dozen_sort(A, &A_top, B, &B_top);
	ft_printf("[%d]\n", A_top);
	while (A_top >= 0)
	{
		ft_printf("A[%d] = %d\n", A_top, A[A_top]);
		A_top--;
	}
	free(A);
	free(B);
	return (0);
}

//TODO: debug sort_dozen 