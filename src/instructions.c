/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:27:28 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/05 13:38:01 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pa_command(t_stack **a, t_stack **b)
{
	pa(a, b);
	if (!*a)
		wipe(a, b);
}

static void	pb_command(t_stack **a, t_stack **b)
{
	pb(a, b);
	if (!*b)
		wipe(a, b);
}

t_operation	*init_instructions(void)
{
	static t_operation	instructions[11];

	instructions[SA] = (t_operation){"sa\n", sa};
	instructions[SB] = (t_operation){"sb\n", sb};
	instructions[SS] = (t_operation){"ss\n", ss};
	instructions[PA] = (t_operation){"pa\n", pa_command};
	instructions[PB] = (t_operation){"pb\n", pb_command};
	instructions[RA] = (t_operation){"ra\n", ra};
	instructions[RB] = (t_operation){"rb\n", rb};
	instructions[RR] = (t_operation){"rr\n", rr};
	instructions[RRA] = (t_operation){"rra\n", rra};
	instructions[RRB] = (t_operation){"rrb\n", rrb};
	instructions[RRR] = (t_operation){"rrr\n", rrr};
	return (instructions);
}
