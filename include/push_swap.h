/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:49:26 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/03 18:25:56 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR "\033[0;31mError\n\033[m"

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

/* ************************************************************************** */
/*                            			Operations                            */
/* ************************************************************************** */
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

#endif
