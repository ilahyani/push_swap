/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:12:01 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/19 20:47:55 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*get_moves(void)
{
	t_list	*m;
	char	*s;

	m = NULL;
	while (1)
	{
		s = get_next_line(1);
		if (!s) // invalid move should give an error, execute while reading
			break ;
		ft_lstadd_back(&m, ft_lstnew(s));
	}
	return (m);
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
	int		num;
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
	make_moves(&stacks, get_moves(), &a_top, &b_top);
	print_res(&stacks, &a_top, &b_top);
	return (0);
}
