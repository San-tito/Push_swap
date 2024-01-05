/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:16:39 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/05 02:04:18 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*top;

	(void)b;
	if (!*a)
		return ;
	top = (**a).next;
	current = *a;
	while ((*current).next)
		current = (*current).next;
	(*current).next = *a;
	(*(*current).next).next = NULL;
	*a = top;
}

void	rb(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*top;

	(void)a;
	if (!*b)
		return ;
	top = (**b).next;
	current = *b;
	while ((*current).next)
		current = (*current).next;
	(*current).next = *b;
	(*(*current).next).next = NULL;
	*b = top;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, b);
	rb(a, b);
}
