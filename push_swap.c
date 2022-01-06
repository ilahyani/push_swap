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

int	isSorted(int *A, int c)
{
	int	i;
	
	i = 0;
	while (i < c - 2 && A[i] <= A[i + 1])
		i++;
	if (i == c - 2)
		return (1);
	return (0);
}

void	sort_three(int *A)
{
	if (A[0] > A[1] && A[0] < A[2])
			ft_printf("ra\n");
	else if (A[1] > A[0] && A[1] > A[2])
	{
		if (A[0] < A[2])
			ft_printf("rra\nsa\n");
		else
			ft_printf("rra");
	}
	else if (A[0] > A[1] && A[0] > A[2])
	{
		if (A[1] > A[2])
			ft_printf("sa\nrra\n");
		else
			ft_printf("ra\n");
	}
}
void	sort_five(int *A)
{
	ft_printf("pb\npb\n");
	sort_three(A + 2);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*A = NULL;

	i = 1;
	if (argc == 1)
		return (0);
	A = malloc (sizeof(int) * argc - 1);
	if (!A)
		return (0);
	while (i < argc)
	{
		A[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (isSorted(A, argc))
	{
		free(A);
		return (0);
	}
	else if (argc == 4)
		sort_three(A);
	else if (argc == 6)
		sort_five(A);
	free(A);
	return (0);
}
