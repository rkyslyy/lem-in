#ifndef LEM_IN_LEM_INC_H
#define LEM_IN_LEM_INC_H

# include "../libft/libft.h"

typedef struct		s_link
{
	char			*name;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char 			*room_name;
	unsigned int	room_id;
	t_link			*links;
	struct s_room	*next;
}					t_room;

typedef struct 		s_road
{
	char 			*name;
	struct s_road	*next;
}					t_road;

typedef struct		s_path
{
	t_road			*road;
	int				closed;
}					t_path;

typedef struct		s_paths
{
	t_path			*path;
	struct s_paths	*next;
}					t_paths;

t_room	*ft_new_room(char *name);
void	ft_add_room(t_room **rooms, char *name);
void	ft_add_link(char *from, char *to, t_room **rooms);
t_paths	*ft_init_path(t_room *start);
t_room	*ft_find_last_room(t_path *path, t_room *start);
void	ft_get_paths(t_paths *paths, t_room *start);
void	ft_print_maze(t_room *start);
void	ft_print_path(t_path *path);
void	ft_print_paths(t_paths *paths);

#endif
