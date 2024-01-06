/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:13:32 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/06 20:09:47 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	push(a, (**b).value);
	if (!*a)
		wipe(a, b);
	pop(b);
}

void	pb(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	push(b, (**a).value);
	if (!*b)
		wipe(a, b);
	pop(a);
}
