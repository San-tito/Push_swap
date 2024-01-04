/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:16:39 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/04 02:50:47 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*top;

	if (!*a)
		return ;
	top = *a;
	while ((**a).next)
		*a = (**a).next;
	(**a).next = top;
}

void	rb(t_stack **b)
{
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
