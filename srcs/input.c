/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:22:36 by satkins           #+#    #+#             */
/*   Updated: 2018/01/23 15:22:38 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_args(int argc, char **argv, t_queue *queue, int debug)
{
	int		curr;
	int		lim;
	int		*numbrs;
	int		len;
	int 	i;

	lim = debug ? 2 : 1;
	len = argc - lim;
	numbrs = ft_memalloc(sizeof(int) * (len));
	while (argc > lim)
		if (is_numstr(argv[--argc]))
		{
			curr = ft_atoi(argv[argc]);
			if (curr != ft_atoll(argv[argc]))
				handle_error(numbrs);
			numbrs[argc - lim] = curr;
			i = argc - lim;
			while (++i < len)
				if (numbrs[i] == curr)
					handle_error(numbrs);
			ft_queuepush(queue, &curr, sizeof(int));
		}
		else
			handle_error(NULL);
	free(numbrs);
}
