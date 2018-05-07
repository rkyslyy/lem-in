#include "../inc/lem-inc.h"

int 		ft_start_has_no_links(t_room *start)
{
	t_room *ptr;

	ptr = start;
	while (ptr)
	{
		if (ptr->start == 1 && ptr->links == NULL)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int 		ft_init_maze(size_t *ants_q, char **line)
{
	get_next_line(0, line);
	if (!ft_strlen(*line))
	{
		free(*line);
		ft_putendl_fd("Error", 1);
		return (0);
	}
	if (ft_invalid_ants(*line, ants_q))
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	get_next_line(0, line);
	while (ft_is_comment(*line))
	{
		ft_strdel(line);
		get_next_line(0, line);
	}
	return (1);
}

int		ft_init_rooms(t_room **start, char *line)
{
	char *work;

	if (ft_is_room(line))
	{
		if (ft_invalid_coordinates(line))
		{
			free(line);
			ft_putendl_fd("Error", 1);
			return (0);
		}
		*start = ft_new_room(line, 0);
		free(line);
		return (1);
	}
	else if ((ft_strequ(line, "##start") || ft_strequ(line, "##end")))
	{
		get_next_line(0, &work);
		if (!ft_is_room(work))
		{
			free(work);
			free(line);
			ft_putendl_fd("Error", 1);
			return (0);
		}
		if (ft_strequ(line, "##start"))
			*start = ft_new_room(work, 1);
		if (ft_strequ(line, "##end"))
			*start = ft_new_room(work, 2);
		free(line);
		free(work);
	}
	else
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	return (1);
}

int    ft_case_start(t_room **start, char **line)
{
    if (!ft_start_exists(*start))
    {
        ft_strdel(line);
        get_next_line(0, line);
        if (ft_is_room(*line))
        {
            ft_add_room(start, *line, 1);
            ft_strdel(line);
        }
        else
        {
            ft_strdel(line);
            ft_putendl_fd("Error", 1);
            return (0);
        }
    }
    else
    {
        ft_strdel(line);
        ft_putendl_fd("Error", 1);
        return (0);
    }
    return (1);
}

int    ft_case_end(t_room **start, char **line)
{
    if (!ft_end_exists(*start))
    {
        ft_strdel(line);
        get_next_line(0, line);
        if (ft_is_room(*line))
        {
			ft_add_room(start, *line, 2);
			ft_strdel(line);
        }
        else
        {
            ft_strdel(line);
            ft_putendl_fd("Error", 1);
            return (0);
        }
    }
    else
    {
        ft_strdel(line);
        ft_putendl_fd("Error", 1);
        return (0);
    }
    return (1);
}

int		ft_get_maze_part_1(t_room **start, size_t *ants_q, char **transfer)
{
	char *line;

	if (!ft_init_maze(ants_q, &line))
		return (0);
	if (!ft_init_rooms(start, line))
		return (0);
	while (get_next_line(0, &line) && ft_strlen(line) && !ft_is_link(line))
	{
		if (ft_is_room(line) && (ft_invalid_coordinates(line) || ft_room_exists(*start, line) ||
								ft_coordinates_exist(*start, line)))
		{
			ft_strdel(&line);
			ft_putendl_fd("Error", 1);
			return (0);
		}
		if (ft_is_room(line))
			ft_add_room(start, line, 0);
		if (ft_strequ(line, "##start")) {
			if (!ft_case_start(start, &line))
				return (0);
			continue;
		}
		if (ft_strequ(line, "##end")) {
			if (!ft_case_end(start, &line))
				return (0);
			continue;
		}
		if (!ft_is_room(line) && !ft_strequ(line, "##start") && !ft_strequ(line, "##end"))
		{
			ft_strdel(&line);
			ft_putendl_fd("Error", 1);
			return (0);
		}
		ft_strdel(&line);
	}
    if ((!ft_strlen(line) && !ft_is_link(line)) || !ft_start_end_present(*start) ||
			ft_start_has_no_links(*start))
    {
        ft_putendl_fd("Error", 1);
        return (0);
    }
    *transfer = ft_strdup(line);
	ft_strdel(&line);
	return (1);
}