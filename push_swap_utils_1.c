/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:09:43 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/17 17:29:43 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a, int a_top)
{
	int	tmp;

	tmp = a[a_top - 1];
	a[a_top - 1] = a[a_top];
	a[a_top] = tmp;
	ft_printf("sa\n");
}

void	sb(int *b, int b_top)
{
	int	tmp;

	tmp = b[b_top - 1];
	b[b_top - 1] = b[b_top];
	b[b_top] = tmp;
	ft_printf("sb\n");
}

void	ss(int *a, int a_top, int *b, int b_top)
{
	sa(a, a_top);
	sb(b, b_top);
	ft_printf("ss\n");
}

void	pa(int *a, int *b, int *b_top, int *a_top)
{
	// Handle the stack overflow/underflow case (if (b_top++ > B_size) || (b_top-- < 0) then exit(1))
	(*a_top)++;
	a[*a_top] = b[*b_top];
	(*b_top)--;
	ft_printf("pa\n");
}

void	pb(int *a, int *b, int *b_top, int *a_top)
{
	(*b_top)++;
	b[*b_top] = a[*a_top];
	(*a_top)--;
	ft_printf("pb\n");
}

void	ra(int *a, int a_top)
{
	int	tmp;

	while (a_top > 0)
	{
		tmp = a[a_top - 1];
		a[a_top - 1] = a[a_top];
		a[a_top] = tmp;
		a_top--;
	}	
	ft_printf("ra\n");
}

void	rb(int *b, int b_top)
{
	int	tmp;

	while (b_top > 0)
	{
		tmp = b[b_top - 1];
		b[b_top - 1] = b[b_top];
		b[b_top] = tmp;
		b_top--;
	}
	ft_printf("rb\n");
}

void	rr(int *a, int *b, int a_top, int b_top)
{
	ra(a, a_top);
	rb(b, b_top);
	ft_printf("rb\n");
}

void	rra(int *a, int a_top)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < a_top)
	{
		tmp = a[i];
		a[i] = a[i + 1];
		a[i + 1] = tmp;
		i++;
	}
	ft_printf("rra\n");
}

void	rrb(int *b, int b_top)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < b_top)
	{
		tmp = b[i];
		b[i] = b[i + 1];
		b[i + 1] = tmp;
		i++;
	}
	ft_printf("rrb\n");
}

void	rrr(int *a, int *b, int a_top, int b_top)
{
	rra(a, a_top);
	rrb(b, b_top);
	ft_printf("rrr\n");
}
