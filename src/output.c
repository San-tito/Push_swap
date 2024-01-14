/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:58:28 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/14 17:23:50 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putchar(char c, int fd)
{
	if (fd == -1)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr(char *s, int fd)
{
	if (!s || fd == -1)
		return ;
	while (*s)
		ft_putchar(*s++, fd);
}

void	ft_putnbr(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, fd);
		ft_putnbr(n % 10, fd);
	}
	else
		ft_putchar((n + '0'), fd);
}

void	display_colored(char *s, char *color, int fd)
{
	ft_putstr(color, fd);
	ft_putstr(s, fd);
	ft_putstr(RESET, fd);
}

void	ft_putstacks(t_stack *a, t_stack *b)
{
	ft_putstr("\n", STDOUT_FILENO);
	while (a || b)
	{
		if (a)
		{
			ft_putnbr((*a).value, STDOUT_FILENO);
			ft_putstr(" ", STDOUT_FILENO);
			a = (*a).next;
		}
		else
			ft_putstr("  ", STDOUT_FILENO);
		if (b)
		{
			ft_putnbr((*b).value, STDOUT_FILENO);
			ft_putstr(" ", STDOUT_FILENO);
			b = (*b).next;
		}
		else
			ft_putstr("  ", STDOUT_FILENO);
		ft_putstr("\n", STDOUT_FILENO);
	}
	ft_putstr("_ _\n", STDOUT_FILENO);
	ft_putstr("A B\n", STDOUT_FILENO);
	ft_putstr("\n", STDOUT_FILENO);
}

void	perform_and_log(t_stack **a, t_stack **b, int index)
{
	t_operation	*instructions;
	t_operation	instruction;

	instructions = init_instructions();
	instruction = *(instructions + index);
	ft_putstr(instruction.order, STDOUT_FILENO);
	instruction.command(a, b);
	//ft_putstacks(*a, *b);
}
