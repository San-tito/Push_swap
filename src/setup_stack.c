/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:14:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/03 18:30:00 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s, int fd)
{
	if (!s || fd == -1)
		return ;
	while (*s)
		write(fd, s++, 1);
}

void	setup_stack(t_stack **stack, char **argv, int argc)
{
	int	nbr;
	int	has_error;

	has_error = 0;
	while (1 < argc--)
	{
		validate_syntax(*(argv + argc), &has_error);
		nbr = ft_atoi(*(argv + argc), &has_error);
		search_for_duplicate(*stack, nbr, &has_error);
		push(stack, nbr);
		if (has_error || !*stack)
		{
			clear_stack(stack);
			ft_putstr(ERROR, STDERR_FILENO);
			exit(1);
		}
	}
}
