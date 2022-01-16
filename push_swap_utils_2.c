#include "push_swap.h"

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
