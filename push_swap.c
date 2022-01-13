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
	(*A_top)++; // Handle the stack overflow/underflow case (if (B_top++ > B_size) || (B_top-- < 0) then exit(1))
	*(A + *A_top) = *(B + *B_top);
	(*B_top)--;
	ft_printf("pa\n");
}

void	pb(int *A, int *B, int *B_top, int *A_top)
{
	(*B_top)++;
	*(B + *B_top) = *(A + *A_top);
	(*A_top)--;
	ft_printf("pb\n");
}

void	ra(int *A, int A_top)
{
	int tmp;

	while (A_top > 0)
	{
		tmp = *(A + A_top - 1);
		*(A + A_top -1) = *(A + A_top );
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
		tmp = *(B + B_top - 1);
		*(B + B_top - 1) = *(B + B_top);
		*(B + B_top) = tmp;
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

void	smallest_to_top(int *A, int *A_top)
{
	int	i;
	int	idx;

	i = 0;
	idx = 1;
	while (i <= *A_top)
	{
		if (A[idx] > A[i])
			idx = i;
		i++;
	}
	if (idx == *A_top)
		return ;
	if (idx < (*A_top) / 2)
	{
		while (idx >= 0)
		{
			rra(A, *A_top);
			idx--;
		}
	}
	else
	{	
		while (idx < *A_top)
		{
			ra(A, *A_top);
			idx++;
		}
	}
}

void	dozen_sort(int *A, int *A_top, int *B, int *B_top)
{
	int	count;
	int	i;

	count = *A_top + 1;
	i = count;
	while (count > 3)
	{
		if (isSorted(A, *A_top))
			break ;
		//printf("B4 smallest to top -------------------------------------\n");
		//for (int k = *A_top; k >= 0; k--)
		//	ft_printf("A[%d] = %d | ", k, A[k]);
		//printf("\n");
		smallest_to_top(A, A_top);
		// printf("A_top before pb -> %d\n", *A_top);
		// printf("B_top before pb -> %d\n", *B_top);
		//printf("after smallest to top-----------------------------------\n");
		//for (int k = *A_top; k >= 0; k--)
		//	ft_printf("A[%d] = %d | ", k, A[k]);
		//printf("\n");
		pb(A, B, B_top, A_top);
		//printf("after pb------------------------------------------------\n");
		//for (int b = *B_top; b >= 0; b--)
		//	ft_printf("B[%d] = %d | ", b, B[b]);
		//printf("\n");
		//printf("--------------------------------------------------------\n");
		// printf("A_top after pb  -> %d\n", *A_top);
		// printf("B_top after pb  -> %d\n", *B_top);
		count--;
	}
	if (!isSorted(A, *A_top))
		sort_three(A, *A_top);
	while (count < i)
	{
		// printf("A_top before pa -> %d\n", *A_top);
		// printf("B_top before pa -> %d\n", *B_top);
		pa(A, B, B_top, A_top);
		// printf("A_top after pa  -> %d\n", *A_top);
		// printf("B_top after pa  -> %d\n", *B_top);
		count++;
	}
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
	A_top = argc - 2;
	B_top = -1;
	argc -= 1;
	i = 0;
	while (i <= A_top)
		A[i++] = ft_atoi(argv[argc--]);	//Need an error msg if input ain't int
	for (i = A_top; i >= 0; i--)
		ft_printf("A[%d] = %d\n", i, A[i]);
	if (isSorted(A, A_top))
	{
		//ft_printf("already sorted");
		free(A);
		free(B);
		return (0);
	}
	else if (argc == 4)
		sort_three(A, A_top);
	else if (argc <  12)
		dozen_sort(A, &A_top, B, &B_top);
	// ft_printf("[%d]\n", A_top);
	// ft_printf("[%d]\n", B_top);
	for (i = A_top; i >= 0; i--)
		ft_printf("A[%d] = %d\n", i, A[i]);
	free(A);
	free(B);
	return (0);
}
