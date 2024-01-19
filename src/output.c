/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:58:28 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/19 13:46:53 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putchar(char c, int fd)
{
	if (fd == -1)
		return ;
	write(fd, &c, 1);
}

static void	ft_putstr(char *s, int fd)
{
	if (!s || fd == -1)
		return ;
	while (*s)
		ft_putchar(*s++, fd);
}

void	display_colored(char *s, char *color, int fd)
{
	ft_putstr(color, fd);
	ft_putstr(s, fd);
	ft_putstr(RESET, fd);
}

void	perform_and_log(t_stack **a, t_stack **b, int index)
{
	t_operation	*instructions;
	t_operation	instruction;

	instructions = init_instructions();
	instruction = *(instructions + index);
	ft_putstr(instruction.order, STDOUT_FILENO);
	instruction.command(a, b);
}
