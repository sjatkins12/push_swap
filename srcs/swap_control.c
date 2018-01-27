/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:36:00 by satkins           #+#    #+#             */
/*   Updated: 2018/01/22 16:36:01 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_control_help(char *instruct, t_queue *a, t_queue *b)
{
	if (!ft_strcmp(instruct, "ra"))
		rotate(a);
	else if (!ft_strcmp(instruct, "rb"))
		rotate(b);
	else if (!ft_strcmp(instruct, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strcmp(instruct, "rra"))
		rev_rotate(a);
	else if (!ft_strcmp(instruct, "rrb"))
		rev_rotate(b);
	else if (!ft_strcmp(instruct, "rrr"))
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else
		handle_error(NULL);
}


void	swap_control(char *instruct, t_queue *a, t_queue *b, t_quick_look *s)
{
	g_count += 1;
	if (!ft_strcmp(instruct, "sa"))
		swap_top(a);
	else if (!ft_strcmp(instruct, "sb"))
		swap_top(b);
	else if (!ft_strcmp(instruct, "ss"))
	{
		swap_top(a);
		swap_top(b);
	}
	else if (!ft_strcmp(instruct, "pa"))
		push_top(a, b);
	else if (!ft_strcmp(instruct, "pb"))
		push_top(b, a);
	else
		swap_control_help(instruct, a, b);
	if (s)
		lookups(s, a, b);
}
