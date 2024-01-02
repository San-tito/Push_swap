/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:58:16 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/02 14:09:00 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pop(t_stack **stack)
{
	t_stack	*temp;

	temp = (**stack).next;
	free(*stack);
	*stack = temp;
}

void	clear_stack(t_stack **stack)
{
	while (*stack)
		pop(stack);
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
