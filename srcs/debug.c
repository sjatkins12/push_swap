/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:27:41 by satkins           #+#    #+#             */
/*   Updated: 2018/01/22 16:27:43 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lookups(t_quick_look *state, t_queue *a, t_queue *b)
{
	ft_bzero(state, sizeof(t_quick_look));
	if (a->first)
	{
		state->a0 = a->first->content;
		state->an = a->last->content;
		if (a->first->next && (state->a1 = a->first->next->content))
			if (a->first->next->next)
				state->a2 = a->first->next->next->content;
		if (a->last->previous)
			state->an1 = a->last->previous->content;
	}
	if (b->first)
	{
		state->b0 = b->first->content;
		state->bn = b->last->content;
		if (b->first->next && (state->b1 = b->first->next->content))
			if (b->first->next->next)
				state->b2 = b->first->next->next->content;
		if (b->last->previous && (state->bn1 = b->last->previous->content))
			if (b->last->previous->previous)
				state->bn2 = b->last->previous->previous->content;
	}
}

void	debuger(t_node *node, t_node *hold, char *instruct)
{
	int	*tmp;
	int num_len;

	if (instruct)
	{
		write(2, "\nInstruction: ", 13);
		ft_putendl(instruct);
	}
	write(2, "Stack_A\t\tStack_B\n", 17);
	while (node || hold)
	{
		// if (node)
		// 	printf("%p <----- %p ------> %p\n", node->previous, node, node->next);
		if (node)
		{
			tmp = node->content;
			num_len = ft_putnbr_fd(*tmp, 2);
			node = node->next;
		}
		else if ((num_len = 1))
			ft_putchar_fd('x', 2);
		while (10 - (++num_len) >= 0)
			ft_putchar_fd(' ', 2);
		ft_putchar_fd('\t', 2);
		if (hold)
		{
			tmp = hold->content;
			ft_putnbr_fd(*tmp, 2);
			hold = hold->next;
		}
		else
			ft_putchar_fd('x', 2);
		ft_putchar_fd('\n', 2);
		
	}
}
