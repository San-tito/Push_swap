/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:49:26 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/03 17:17:59 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR "\033[0;31mError\n"

/* ************************************************************************** */
/*                                Stack definition                            */
/* ************************************************************************** */
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

/* ************************************************************************** */
/*                          Argument parsing functions                        */
/* ************************************************************************** */
int					ft_atoi(char *str, int *has_error);
void				validate_syntax(char *str, int *has_error);
void				search_for_duplicate(t_stack *stack, int value,
						int *has_error);

/* ************************************************************************** */
/*                              Stack methods functions                       */
/* ************************************************************************** */
void				push(t_stack **stack, int value);
void				clear_stack(t_stack **stack);

/* ************************************************************************** */
/*                               Setup stack functions                        */
/* ************************************************************************** */
void				setup_stack(t_stack **stack, char **argv, int argc);

#endif
