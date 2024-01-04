/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:58:16 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/04 19:29:09 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop(t_stack **stack)
{
	t_stack	*temp;

	temp = (**stack).next;
	free(*stack);
	*stack = temp;
}

void	clear_stack(t_stack **stack)
{
	if (!stack)
		return ;
	while (*stack)
		pop(stack);
}

int	size(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp = (*temp).next;
		i++;
	}
	return (i);
}

void	push(t_stack **stack, int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (clear_stack(stack));
	(*new).value = value;
	(*new).next = *stack;
	*stack = new;
}
