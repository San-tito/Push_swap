/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:51:19 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/04 19:09:03 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printStacks(t_stack *stackA, t_stack *stackB)
{
	while (stackA || stackB)
	{
		if (stackA)
		{
			printf("%d ", stackA->value);
			stackA = stackA->next;
		}
		else
			printf("  ");
		if (stackB)
		{
			printf("%d ", stackB->value);
			stackB = stackB->next;
		}
		else
			printf("  ");
		printf("\n");
	}
	printf("_ _\n");
	printf("a b\n");
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 3)
		return (0);
	setup_stack(&a, argv, argc);
	printStacks(a, b);
	rra(&a);	
	printStacks(a, b);
	clear_stack(&a);
	return (0);
}
