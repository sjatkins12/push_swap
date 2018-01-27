/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:22:12 by satkins           #+#    #+#             */
/*   Updated: 2018/01/22 14:22:14 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"

int g_count;

typedef struct	s_quick_look
{
	int 		*a0;
	int 		*an;
	int 		*a1;
	int 		*an1;
	int 		*a2;
	int 		*bn;
	int 		*b0;
	int 		*b1;
	int 		*b2;
	int 		*bn1;
	int 		*bn2;
}				t_quick_look;

void	rev_rotate(t_queue *queue);
void	rotate(t_queue *queue);
void	push_top(t_queue *dst, t_queue *src);
void	swap_top(t_queue *queue);
void	debuger(t_node *node, t_node *hold, char *instruct);
void	swap_control(char *instruct, t_queue *a, t_queue *b, t_quick_look *s);
void	read_args(int argc, char **argv, t_queue *queue, int debug);
void	lookups(t_quick_look *state, t_queue *a, t_queue *b);


#endif
