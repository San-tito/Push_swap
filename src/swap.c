/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:15:04 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/05 02:04:59 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, t_stack **b)
{
	t_stack	*top;

	(void)b;
	if (size(a) < 2)
		return ;
	top = (**a).next;
	(**a).next = (*top).next;
	(*top).next = *a;
	*a = top;
}

void	sb(t_stack **a, t_stack **b)
{
	t_stack	*top;

	(void)a;
	if (size(b) < 2)
		return ;
	top = (**b).next;
	(**b).next = (*top).next;
	(*top).next = *b;
	*b = top;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, b);
	sb(a, b);
}
