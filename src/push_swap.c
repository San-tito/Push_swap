/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:51:19 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/02 17:28:59 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	printStack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		printf("%d\n", (*temp).value);
		temp = (*temp).next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 3)
		return (1);
	setup_stack(&a, argv, argc);
	printStack(a);
	(void)b;
	return (0);
}
