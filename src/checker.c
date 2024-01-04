/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:24 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/04 19:42:11 by sguzman          ###   ########.fr       */
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
	if (!ft_strcmp(instruction, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(instruction, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp(instruction, "sa\n"))
		sa(a);
	else if (!ft_strcmp(instruction, "sb\n"))
		sb(b);
	else if (!ft_strcmp(instruction, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(instruction, "ra\n"))
		ra(a);
	else if (!ft_strcmp(instruction, "rb\n"))
		rb(b);
	else if (!ft_strcmp(instruction, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(instruction, "rra\n"))
		rra(a);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(instruction, "rrr\n"))
		rrr(a, b);
	else
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
