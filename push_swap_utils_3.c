#include "push_swap.h"

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

void	biggest_to_top(int *B, int *B_top)
{
	int	idx;

	idx = find_biggest(B, B_top);
	if (idx == *B_top)
		return ;
	if (idx < (*B_top) / 2)
	{
		while (idx >= 0)
		{
			rrb(B, *B_top);
			idx--;
		}
	}
	else
	{	
		while (idx < *B_top)
		{
			rb(B, *B_top);
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
	int	count;
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
	free(key_nbr);
	if (!isSorted(A, *A_top))
	{
		if (*A_top > 2)
			ten_sort(A, A_top, B, B_top);
		else
			three_sort(A, *A_top);
	}
	count = *B_top + 1;
	while (count > 0)
	{
		biggest_to_top(B, B_top);
		pa(A, B, B_top, A_top);
		count--;
	}
}