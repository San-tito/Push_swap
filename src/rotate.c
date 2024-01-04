/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:16:39 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/04 15:15:55 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*current;
	t_stack	*top;
	t_stack	*bottom;

	if (!*a)
		return ;
	current = *a;
	top = NULL;
	bottom = NULL;
	while (current->next)
	{
		bottom = current;
		current = current->next;
	}
	top = bottom->next;
	bottom->next = NULL;
	current->next = *a;
	*a = top;
}

void	rb(t_stack **b)
{
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
