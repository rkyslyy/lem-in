#include "../inc/lem-inc.h"

int main(void)
{
	t_room	*start;
	t_paths	*paths;

	start = ft_new_room("start");
	ft_add_room(&start, "1");
	ft_add_room(&start, "2");
	ft_add_room(&start, "3");
	ft_add_room(&start, "4");
	ft_add_room(&start, "5");
	ft_add_room(&start, "6");
	ft_add_room(&start, "7");
	ft_add_room(&start, "8");
	ft_add_room(&start, "finish");
	ft_add_link("start", "1", &start);
	ft_add_link("1", "2", &start);
	ft_add_link("1", "3", &start);
	ft_add_link("1", "6", &start);
	ft_add_link("2", "7", &start);
	ft_add_link("2", "8", &start);
	ft_add_link("2", "1", &start);
	ft_add_link("2", "6", &start);
	ft_add_link("3", "1", &start);
	ft_add_link("3", "4", &start);
	ft_add_link("3", "5", &start);
	ft_add_link("3", "6", &start);
	ft_add_link("4", "3", &start);
	ft_add_link("5", "3", &start);
	ft_add_link("5", "6", &start);
	ft_add_link("6", "1", &start);
	ft_add_link("6", "2", &start);
	ft_add_link("6", "3", &start);
	ft_add_link("6", "5", &start);
	ft_add_link("6", "finish", &start);
	ft_add_link("7", "2", &start);
	ft_add_link("8", "2", &start);
	ft_add_link("finish", "6", &start);
	ft_print_maze(start);
	paths = ft_init_path(start);
	ft_get_paths(paths, start);
	ft_get_paths(paths, start);
	ft_get_paths(paths, start);
	ft_get_paths(paths, start);
	ft_get_paths(paths, start);
	ft_get_paths(paths, start);
	ft_get_paths(paths, start);
	ft_get_paths(paths, start);
	ft_get_paths(paths, start);
	ft_print_paths(paths);
	return 0;
}
