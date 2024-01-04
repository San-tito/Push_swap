/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:19:47 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/04 16:37:38 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*current;
	t_stack	*top;

	if (!*a)
		return ;
	current = *a;
	while ((*(*current).next).next)
		current = (*current).next;
	top = (*current).next;
	(*current).next = NULL;
	(*top).next = *a;
	*a = top;
}

void	rrb(t_stack **b)
{
	t_stack	*current;
	t_stack	*top;

	if (!*b)
		return ;
	current = *b;
	while ((*(*current).next).next)
		current = (*current).next;
	top = (*current).next;
	(*current).next = NULL;
	(*top).next = *b;
	*b = top;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
