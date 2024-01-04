/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:15:04 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/03 23:58:02 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*top;

	if (size(a) < 2)
		return ;
	top = (**a).next;
	(**a).next = (*top).next;
	(*top).next = *a;
	*a = top;
}

void	sb(t_stack **b)
{
	t_stack	*top;

	if (size(b) < 2)
		return ;
	top = (**b).next;
	(**b).next = (*top).next;
	(*top).next = *b;
	*b = top;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
