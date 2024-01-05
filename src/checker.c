/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:24 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/05 10:36:28 by sguzman          ###   ########.fr       */
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
	t_operation	*instructions;
	int			i;

	instructions = init_instructions();
	i = 0;
	while (i < 11)
	{
		if (!ft_strcmp(instruction, (*(instructions + i)).order))
			return ((*(instructions + i)).command(a, b));
		i++;
	}
	wipe(a, b);
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
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (stack_is_sorted(a) && !b)
		display_colored("OK\n", GREEN, STDOUT_FILENO);
	else
		display_colored("KO\n", RED, STDOUT_FILENO);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
