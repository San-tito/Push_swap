/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:51:19 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/01 19:29:42 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setup_stack(t_stack *stack, char **argv)
{
	int	has_error;

	has_error = 0;
	while (*argv)
	{
		validate_syntax(*argv, &has_error);
		ft_atoi(*argv, &has_error);
		if (has_error)
			exit(1);
		argv++;
	}
	(void)stack;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 3)
		return (1);
	setup_stack(&a, argv + 1);
	(void)b;
	return (0);
}
