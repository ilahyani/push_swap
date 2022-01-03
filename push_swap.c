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
		tmp = tmp->next;
	if(!(tmp->next))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list *a;

	i = 1;
	while (i < argc)
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i++])));
	if (isSorted(a))
		ft_printf("sorted\n");
	else
		ft_printf("sortedn't\n");
	return (0);
}
