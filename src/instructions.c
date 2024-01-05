/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:27:28 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/05 10:44:19 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pa_command(t_stack **a, t_stack **b)
{
	pa(a, b);
	if (!a)
		wipe(a, b);
}

static void	pb_command(t_stack **a, t_stack **b)
{
	pb(a, b);
	if (!b)
		wipe(a, b);
}

void	perform_and_log(t_stack **a, t_stack **b, t_operation instruction)
{
	ft_putstr(instruction.order, STDOUT_FILENO);
	instruction.command(a, b);
}

t_operation	*init_instructions(void)
{
	static t_operation	instructions[11];

	*(instructions + 0) = (t_operation){"sa\n", sa};
	*(instructions + 1) = (t_operation){"sb\n", sb};
	*(instructions + 2) = (t_operation){"ss\n", ss};
	*(instructions + 3) = (t_operation){"pa\n", pa_command};
	*(instructions + 4) = (t_operation){"pb\n", pb_command};
	*(instructions + 5) = (t_operation){"ra\n", ra};
	*(instructions + 6) = (t_operation){"rb\n", rb};
	*(instructions + 7) = (t_operation){"rr\n", rr};
	*(instructions + 8) = (t_operation){"rra\n", rra};
	*(instructions + 9) = (t_operation){"rrb\n", rrb};
	*(instructions + 10) = (t_operation){"rrr\n", rrr};
	return (instructions);
}
