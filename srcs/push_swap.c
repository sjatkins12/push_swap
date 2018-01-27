/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:26:38 by satkins           #+#    #+#             */
/*   Updated: 2018/01/22 12:26:46 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ********************************************************** */
/* Input: a (queue to check), direction (1 acending, -1 decs) */
/* *** Output: -1 (Empty queue), 1 (sorted), 0 (unsorted) *** */
/* ********************************************************** */

int 	check_sorted_queue(t_queue *a, int direction)
{
	t_node	*node;
	int 	*content[2];

	node = a->first;
	if (node)
	{
		content[0] = NULL;
		content[1] = node->content;
	}
	else
		return (-1);
	while (node)
	{
		content[1] = node->content;
		if (content[0])
		{
			if (direction == 1 && *(content[0]) > *(content[1]))
				return (0);
			else if (direction == -1 && *(content[0]) < *(content[1]))
				return (0);
		}
		content[0] = content[1];
		node = node->next;
	}
	return (1);
}

int 	comparison(int *a, int *b, int *b1)
{
	if (!(a && b && b1))
		return (0);
	if (*b1 > *b)
	{
		if (*a > *b1 || *a < *b)
			return (1);
	}
	else
	{
		if (*a > *b1 && *a < *b)
			return (1);
	}
	return (0);
}

void	sort_queue(t_queue *a, t_queue *b, int debug)
{
	int	is_sorted_flag;
	t_quick_look	lookup;
	int 	i;

	g_count = 0;
	if (check_sorted_queue(a, 1))
		return ;
	// lookups(&lookup, a, b);
	// if (*lookup.a0 > *lookup.a1)
	// 	swap_control("sa", a, b, &lookup);
	// if (*lookup.a0 > *lookup.an)
	// 	swap_control("rra", a, b, &lookup);
	// swap_control("pb", a, b, &lookup);
	// while (*lookup.a0 > *lookup.b0)
	// {
	// 	swap_control("pb", a, b, &lookup);
	// 	if (lookup.a0 && lookup.an && *lookup.a0 > *lookup.an && *lookup.an > *lookup.b0)
	// 		swap_control("rra", a, b, &lookup);
	// 	if (lookup.a0 && lookup.a1 && *lookup.a0 > *lookup.a1 && *lookup.a1 > *lookup.b0)
	// 		swap_control("sa", a, b, &lookup);
	// }
	swap_control("pb", a, b, &lookup);
	swap_control("pb", a, b, &lookup);
	i = 0;
	while (a->first)
	{
		if (comparison(lookup.a0, lookup.bn, lookup.b0))
			swap_control("pb", a, b, &lookup);
		else if (comparison(lookup.a0, lookup.bn1, lookup.bn))
		{
			swap_control("rrb", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.a0, lookup.b0, lookup.b1))
		{
			swap_control("rb", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.a1, lookup.bn, lookup.b0))
		{
			swap_control("ra", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.a1, lookup.b0, lookup.b1))
		{
			swap_control("rr", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.an, lookup.bn, lookup.b0))
		{
			swap_control("rra", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.an, lookup.bn1, lookup.bn))
		{
			swap_control("rrr", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.an1, lookup.bn, lookup.b0))
		{
			swap_control("rra", a, b, &lookup);
			swap_control("rra", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.an1, lookup.bn1, lookup.bn))
		{
			swap_control("rrr", a, b, &lookup);
			swap_control("rra", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.an1, lookup.bn2, lookup.bn1))
		{
			swap_control("rrr", a, b, &lookup);
			swap_control("rrr", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.an, lookup.bn2, lookup.bn1))
		{
			swap_control("rrr", a, b, &lookup);
			swap_control("rrb", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.a0, lookup.b1, lookup.b2))
		{
			swap_control("rb", a, b, &lookup);
			swap_control("rb", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.a0, lookup.b1, lookup.b2))
		{
			swap_control("rb", a, b, &lookup);
			swap_control("rb", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.a0, lookup.bn2, lookup.bn1))
		{
			swap_control("rrb", a, b, &lookup);
			swap_control("rrb", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.a1, lookup.b1, lookup.b2))
		{
			swap_control("rr", a, b, &lookup);
			swap_control("rb", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.a1, lookup.bn1, lookup.bn))
		{
			swap_control("ra", a, b, &lookup);
			swap_control("rrb", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.a2, lookup.bn, lookup.b0))
		{
			swap_control("ra", a, b, &lookup);
			swap_control("ra", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.a2, lookup.b0, lookup.b1))
		{
			swap_control("rr", a, b, &lookup);
			swap_control("ra", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.a2, lookup.b1, lookup.b2))
		{
			swap_control("rr", a, b, &lookup);
			swap_control("rr", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		else if (comparison(lookup.an, lookup.b0, lookup.b1))
		{
			swap_control("rra", a, b, &lookup);
			swap_control("rb", a, b, &lookup);
			swap_control("pb", a, b, &lookup);
		}
		// else if (++i % 5 == 0)
		// 	swap_control("rr", a, b, &lookup);
		else
			swap_control("rb", a, b, &lookup);
		if (debug)
			debuger(a->first, b->first, NULL);
	}
	while (*lookup.bn > *lookup.b0)
		swap_control("rb", a, b, &lookup);
	while (b->first)
		swap_control("pa", a, b, &lookup);
	
	
}

static void	controller(int argc, char **argv, int debug)
{
	t_queue	*a;
	t_queue	*b;
	int 	*nbr;

	a = init_queue();
	b = init_queue();
	read_args(argc, argv, a, debug);
	sort_queue(a, b, debug);
	while (a->first)
	{
		nbr = ft_dequeue(a);
		ft_putnbr(*nbr);
		ft_putchar('\n');
	}
	ft_putnbr(g_count);
	ft_putchar('\n');
}

int	main(int argc, char **argv)
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