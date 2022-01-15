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

int	find_smallest(int *stack, int *top)
{
	int	i;
	int	idx;

	i = 0;
	idx = 1;
	while (i <= *top)
	{
		if (stack[idx] > stack[i])
			idx = i;
		i++;
	}
	return (idx);
}

int	isSorted(int *A, int A_top)
{
	while (A_top > 0 && A[A_top] <= A[A_top - 1])
		A_top--;
	if (!A_top)
		return (1);
	return (0);
}

void	three_sort(int *A, int A_top)
{
	if (A_top == 1 && A[1] > A[0])
		sa(A, A_top); 
	else if (A[0] >= A[1] && A[0] >= A[2])
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
	int	idx;

	idx = find_smallest(A, A_top);
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

void	ten_sort(int *A, int *A_top, int *B, int *B_top)
{
	int	count;
	int	i;

	count = *A_top + 1;
	i = count;
	while (count > 3)
	{
		if (isSorted(A, *A_top))
			break ;
		smallest_to_top(A, A_top);
		pb(A, B, B_top, A_top);
		count--;
	}
	if (!isSorted(A, *A_top))
		three_sort(A, *A_top);
	while (count < i)
	{
		pa(A, B, B_top, A_top);
		count++;
	}
}

int	find_biggest(int *stack, int *top)
{
	int	i;
	int	idx;

	i = 0;
	idx = 1;
	while (i <= *top)
	{
		if (stack[idx] < stack[i])
			idx = i;
		i++;
	}
	return (idx);
}

void	biggest_to_top(int *A, int *A_top)
{
	int	idx;

	idx = find_biggest(A, A_top);
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

int	*find_keynbr(int *A, int A_top)
{
	int *C;
	int	tmp;
	int	i;
	int x;
	int *ret;

	C = malloc(sizeof(int) * (A_top + 1));
	ret = malloc(sizeof(int) * 4);
	if (!C)
		return (0);
	i = 0;
	while (i <= A_top)
	{
		C[i] = A[i];
		i++;
	}
	i--;
	while (i > 0)
	{
		x = find_smallest(C, &i);
		tmp = C[i];
		C[i] = C[x];
		C[x] = tmp;
		i--;
	}
	i = 1;
	while (i < 5)
	{
		ret[i] = C[A_top - (A_top/4) * i];
		i++;
	}
	// ft_printf("    * Sorted C\n");
	// for (int j = A_top; j >= 0; j--)
	// 	ft_printf("C[%d] = %d\n", j, C[j]);
	free (C);
	return (ret);
}

void	dozen_sort(int *A, int *B, int *A_top, int *B_top)
{
	int *key_nbr;
	int	i;
	int	j;
	int	k;
	
	key_nbr = find_keynbr(A, *A_top);
		
	k = 1;
	while (k < 5)
	{
		i = *A_top;
		// ft_printf("    * key_nbr[%d] = %d\n", k, key_nbr[k]);
		while (i >= 0)
		{
			j = i;
			if (A[j] <= key_nbr[k])
			{
				if (j == *A_top)
					pb(A, B, B_top, A_top);
				else if (j < (*A_top) / 2)
				{
					while (j >= 0)
					{
						rra(A, *A_top);
						j--;
					}
					pb(A, B, B_top, A_top);
				}
				else
				{
					while (j < *A_top)
					{
						ra(A, *A_top);
						j++;
					}
					pb(A, B, B_top, A_top);
				}
				i = (*A_top) + 1;
			}
			i--;
		}
		// ft_printf("    * Stack B\n");
		// for (int z = *B_top; z >= 0; z--)
		// 	ft_printf("B[%d] = %d\n", z, B[z]);
		k++;
	}
	// ft_printf("    * Stack A\n");
	// 	for (int z = *A_top; z >= 0; z--)
	// 		ft_printf("A[%d] = %d\n", z, A[z]);
	free(key_nbr);
	ten_sort(A, A_top, B, B_top);

	int	count;
	int	z;

	count = *B_top + 1;
	z = count;
	while (count > 0)
	{
		biggest_to_top(B, B_top);
		pa(A, B, B_top, A_top);
		count--;
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
	if (!A || !B)
		return (0);
	A_top = argc - 2;
	B_top = -1;
	argc -= 1;
	i = 0;
	while (i <= A_top)
		A[i++] = ft_atoi(argv[argc--]);		//Need an error msg if input ain't int
	// ft_printf("------------ unsorted A --------------\n");
	// for (i = A_top; i >= 0; i--)
	// 	ft_printf("A[%d] = %d\n", i, A[i]);
	// ft_printf("------------ sorting A ---------------\n");
	if (isSorted(A, A_top))
	{
		free(A);
		free(B);
		return (0);
	}
	if (A_top == 2)
		three_sort(A, A_top);
	else if (A_top > 2 && A_top <  10)
		ten_sort(A, &A_top, B, &B_top);
	else if (A_top >= 10 && A_top <= 100)
		dozen_sort(A, B, &A_top, &B_top);
	// ft_printf("------------ sorted A ----------------\n");
	// for (i = A_top; i >= 0; i--)
	// 	ft_printf("A[%d] = %d\n", i, A[i]);
	free(B);
	free(A);
	return (0);
}
