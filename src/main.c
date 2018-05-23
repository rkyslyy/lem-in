/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:25:31 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/05/22 15:25:32 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem-inc.h"

int	main(void)
{
	t_room	*start;
	size_t	ants_q;
	char	*transfer;
	t_link	*path;
	char	*line;

	if (!ft_get_maze_part_1(&start, &ants_q, &transfer, line))
		return (1);
	if (!ft_get_maze_part_2(&start, transfer))
	{
		ft_set_depth(start);
		path = ft_find_path(start);
		if (!path)
			return (ft_printf("Error\n"));
		ft_move_ants(ants_q, path, start);
		return (0);
	}
	ft_printf("\n");
	ft_set_depth(start);
	path = ft_find_path(start);
	if (!path)
		return (ft_printf("Error\n"));
	ft_move_ants(ants_q, path, start);
	return (0);
}
