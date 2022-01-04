/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:03:02 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/03 01:52:00 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h> 

int	isSorted(t_list *a)
{
	t_list *tmp;

	tmp = a;
	while (tmp->next && tmp->content < tmp->next->content)
	{
		ft_printf("here\n");
		tmp = tmp->next;
	}
	if(tmp->next)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	t_list *a;
	int	x;

	i = 1;
	a = NULL;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		x = ft_atoi(argv[i++]);
		ft_lstadd_back(&a, ft_lstnew(&x));
	}
	if (!isSorted(a))
		ft_printf("sortedn't\n");
	else
		ft_printf("sorted\n");
	return (0);
}
