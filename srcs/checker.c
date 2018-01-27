/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:26:27 by satkins           #+#    #+#             */
/*   Updated: 2018/01/22 12:26:28 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		read_stdin(t_queue *a, t_queue *b, int debug)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		swap_control(line, a, b, NULL);
		if (debug)
			debuger(a->first, b->first, line);
		// printf("Queue->first: %p Queue->last: %p\n", a->first, a->last);
		free(line);
	}
}

int			check_solution(t_queue *a, t_queue *b)
{
	int		*hold;
	int 	prev;
	int 	first_flag;

	if (b->first)
		return (0);
	first_flag = 0;
	while (a->first)
	{
		hold = ft_dequeue(a);
		if (!first_flag || *hold > prev)
		{
			first_flag = 1;
			prev = *hold;
		}
		else
		{
			free(hold);
			return (0);
		}
		free(hold);
	}
	return (1);
}

static void	controller(int argc, char **argv, int debug)
{
	t_queue	*queue_a;
	t_queue	*queue_b;

	queue_a = init_queue();
	queue_b = init_queue();
	read_args(argc, argv, queue_a, debug);
	read_stdin(queue_a, queue_b, debug);
	if (check_solution(queue_a, queue_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int			main(int argc, char **argv)
{
	int		debug;

	debug = 0;
	if (argc != 1)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'v' && argv[1][2] == '\0')
			debug = 1;
		controller(argc, argv, debug);
	}
}
