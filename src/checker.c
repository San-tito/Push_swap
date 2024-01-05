/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:24 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/05 02:29:13 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static void	exec_instruction(t_stack **a, t_stack **b, char *instruction)
{
	const t_operation	instructions[] = {{"sa\n", sa}, {"sb\n", sb}, {"ss\n",
			ss}, {"pa\n", pa}, {"pb\n", pb}, {"ra\n", ra}, {"rb\n", rb},
			{"rr\n", rr}, {"rra\n", rra}, {"rrb\n", rrb}, {"rrr\n", rrr}};
	size_t				i;

	i = 0;
	while (i < sizeof(instructions))
	{
		if (!ft_strcmp(instruction, (*(instructions + i)).order))
			return ((*(instructions + i)).command(a, b));
		i++;
	}
	wipe(a, b);
}

static void	ok(void)
{
	ft_putstr(GREEN, STDOUT_FILENO);
	ft_putstr("OK\n", STDOUT_FILENO);
	ft_putstr(RESET, STDOUT_FILENO);
}

static void	ko(void)
{
	ft_putstr(RED, STDOUT_FILENO);
	ft_putstr("KO\n", STDOUT_FILENO);
	ft_putstr(RESET, STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (argc < 3)
		return (0);
	setup_stack(&a, argv, argc);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		exec_instruction(&a, &b, line);
		line = get_next_line(STDIN_FILENO);
	}
	if (stack_is_sorted(a) && !b)
		ok();
	else
		ko();
	clear_stack(&a);
	return (0);
}
