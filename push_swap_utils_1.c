/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:09:43 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/16 20:09:47 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *A, int A_top)
{
	int	tmp;

	tmp = A[A_top - 1];
	A[A_top - 1] = A[A_top];
	A[A_top] = tmp;
	ft_printf("sa\n");
}

void	sb(int *B, int B_top)
{
	int	tmp;

	tmp = B[B_top - 1];
	B[B_top - 1] = B[B_top];
	B[B_top] = tmp;
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
	A[*A_top] = B[*B_top];
	(*B_top)--;
	ft_printf("pa\n");
}

void	pb(int *A, int *B, int *B_top, int *A_top)
{
	(*B_top)++;
	B[*B_top] = A[*A_top];
	(*A_top)--;
	ft_printf("pb\n");
}

void	ra(int *A, int A_top)
{
	int tmp;

	while (A_top > 0)
	{
		tmp = A[A_top - 1];
		A[A_top - 1] = A[A_top];
		A[A_top] = tmp;
		A_top--;
	}	
	ft_printf("ra\n");
}

void	rb(int *B, int B_top)
{
	int tmp;

	while (B_top > 0)
	{
		tmp = B[B_top - 1];
		B[B_top - 1] = B[B_top];
		B[B_top] = tmp;
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
		tmp = A[i];
		A[i] = A[i + 1];
		A[i + 1] = tmp;
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
		tmp = B[i];
		B[i] = B[i + 1];
		B[i + 1] = tmp;
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
