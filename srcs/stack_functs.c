/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:21:31 by satkins           #+#    #+#             */
/*   Updated: 2018/01/22 14:21:34 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_queue *queue)
{
	t_node	*to_first;
	t_node	*to_second;

	if (!queue->first)
		return ;
	if (!queue->first->next)
		return ;
	to_second = queue->first;
	to_first = queue->first->next;
	queue->first = to_first;
	to_second->next = to_first->next;
	to_first->next = to_second;
	to_second->previous = to_first;
	to_first->previous = NULL;
	if (!to_second->next)
		queue->last = to_second;
	else
		to_second->next->previous = to_second;
}

void	push_top(t_queue *dst, t_queue *src)
{
	t_node	*hold;

	if (!src->first)
		return ;
	hold = src->first;
	src->first = hold->next;
	if (src->first)
		src->first->previous = NULL;
	hold->next = dst->first;
	if (dst->first)
		dst->first->previous = hold;
	else
		dst->last = hold;
	hold->previous = NULL;
	dst->first = hold;
}

void	rotate(t_queue *queue)
{
	t_node	*hold;

	if (!(hold = queue->first))
		return ;
	queue->first = hold->next;
	if (!queue->first)
	{
		queue->first = hold;
		return ;
	}
	queue->last->next = hold;
	hold->previous = queue->last;
	queue->last = hold;
	hold->next = NULL;
	queue->first->previous = NULL;
}

void	rev_rotate(t_queue *queue)
{
	t_node 	*to_first;
	t_node 	*to_last;

	if (!queue->last || !queue->last->previous || !queue->first)
		return ;
	to_first = queue->last;
	to_last = to_first->previous;
	to_last->next = NULL;
	to_first->next = queue->first;
	queue->first->previous = to_first;
	queue->first = to_first;
	to_first->previous = NULL;
	queue->last = to_last;
}
