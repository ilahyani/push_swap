/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:03:02 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/02 01:33:27 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h> 

int	main(int argc, char **argv)
{
	int	i;
	t_list *a;

	i = 1;
	while (i < argc)
		ft_lstadd_back(&a, ft_lstnew(argv[i++]));
	i = 0;
	while (a)
	{
		printf("%s\n", a->content);
		a = a->next;
	}
	return (0);
}
