#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

void	sa(int *A, int A_top);
void	sb(int *B, int B_top);
void	ss(int *A, int A_top, int *B, int B_top);
void	pa(int *A, int *B, int *B_top, int *A_top);
void	pb(int *A, int *B, int *B_top, int *A_top);
void	ra(int *A, int A_top);
void	rb(int *B, int B_top);
void	rr(int *A, int *B, int A_top, int B_top);
void	rra(int *A, int A_top);
void	rrb(int *B, int B_top);
void	rrr(int *A, int *B, int A_top, int B_top);
int	    isSorted(int *A, int A_top);
void	three_sort(int *A, int A_top);
int 	find_smallest(int *stack, int *top);
void	smallest_to_top(int *A, int *A_top);
void	ten_sort(int *A, int *A_top, int *B, int *B_top);
int	    find_biggest(int *stack, int *top);
void	biggest_to_top(int *B, int *B_top);
int	    *find_keynbr(int *A, int A_top);
void	dozen_sort(int *A, int *B, int *A_top, int *B_top);

#endif