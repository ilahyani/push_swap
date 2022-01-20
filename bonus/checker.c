/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:12:01 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/20 01:27:27 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_moves(t_stack *stacks, int *a_top, int *b_top)
{
	char	*move;

	while (1)
	{
		move = get_next_line(1);
		if (!move) // invalid move should give an error, execute while reading
			break ;
		if (!ft_exec(stacks, move, a_top, b_top))
			return (0);
	}
	return (1);
}

void	print_res(t_stack *stacks, int *a_top, int *b_top)
{
	if (is_sorted(stacks, *a_top) && *b_top == -1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(stacks->a);
	free(stacks->b);
}

int	main(int argc, char **argv)
{
	t_stack	stacks;
	int		i;
	long long	num;
	int		a_top;
	int		b_top;

	if (argc < 2)
		return (0);
	a_top = argc - 2;
	b_top = -1;
	stacks.a = (int *) malloc (sizeof(int) * (argc - 1));
	stacks.b = (int *) malloc (sizeof(int) * (argc - 1));
	argc--;
	i = 0;
	while (i <= a_top)
	{
		num = ft_atoi(argv[argc--]);
		if (error_catch(&stacks, num, i))
			return (0);
		stacks.a[i++] = num;
	}
	if (!get_moves(&stacks, &a_top, &b_top))
		return (0);
	print_res(&stacks, &a_top, &b_top);
	return (0);
}
