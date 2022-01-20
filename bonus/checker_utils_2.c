/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:40:31 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/19 18:40:48 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	free_list(void *node)
{
	if (!node)
		return ;
	free(node);
}

void	ft_exec(t_stack *stacks, void *move, int *a_top, int *b_top)
{
	if (ft_strcmp(move, "sa") == 10)
		sa(stacks, a_top);
	else if (ft_strcmp(move, "sb") == 10)
		sb(stacks, a_top);
	else if (ft_strcmp(move, "ss") == 10)
		ss(stacks, a_top, b_top);
	else if (ft_strcmp(move, "pa") == 10)
		pa(stacks, a_top, b_top);
	else if (ft_strcmp(move, "pb") == 10)
		pb(stacks, a_top, b_top);
	else if (ft_strcmp(move, "ra") == 10)
		ra(stacks, *a_top);
	else if (ft_strcmp(move, "rb") == 10)
		rb(stacks, *b_top);
	else if (ft_strcmp(move, "rr") == 10)
		rr(stacks, *a_top, *b_top);
	else if (ft_strcmp(move, "rra") == 10)
		rra(stacks, *a_top);
	else if (ft_strcmp(move, "rrb") == 10)
		rrb(stacks, *b_top);
	else if (ft_strcmp(move, "rrr") == 10)
		rrr(stacks, *a_top, *b_top);
	else
		write(2, "Error\n", 6);
}

void	make_moves(t_stack *stacks, t_list *moves, int *a_top, int *b_top)
{
	while (moves)
	{
		ft_exec(stacks, moves->content, a_top, b_top);
		moves = moves->next;
	}
	ft_lstclear(&moves, &free_list);
}
