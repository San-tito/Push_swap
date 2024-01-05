/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:58:28 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/05 13:37:59 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s, int fd)
{
	if (!s || fd == -1)
		return ;
	while (*s)
		write(fd, s++, 1);
}

void	display_colored(char *s, char *color, int fd)
{
	ft_putstr(color, fd);
	ft_putstr(s, fd);
	ft_putstr(RESET, fd);
}

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

void	perform_and_log(t_stack **a, t_stack **b, t_operation instruction)
{
	ft_putstr(instruction.order, STDOUT_FILENO);
	instruction.command(a, b);
	// printStacks(*a, *b);
}
