#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/stat.h>
# include <fcntl.h>

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

# include <unistd.h>

# include <math.h>

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

# define SIZE 32

typedef struct s_pos
{
    int x;
    int y;
}   t_pos;

typedef enum e_dir
{
    NONE,
    DOWN,
    RIGHT,
    TOP,
    LEFT
}   t_dir;

typedef struct s_player
{
    t_pos   pos;
    t_pos   prev_pos;
    t_img   *img[16];
    t_dir   dir;
    t_dir   next_dir;
}   t_player;

typedef struct s_game
{
    void        *id;
    void        *win;
    char        **map;
    t_player    player;
    t_img       *floor;
    t_img       *wall;
    t_img       *exit;
    t_img       *item[8];
    t_pos       e_pos;
    int         width;
    int         height;
    int         moves;
    int         item_left;
}   t_game;

// UTILS
int     ft_strlen(const char *s);
int     ft_strline(char **ss);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);

// GNL
char	*get_next_line(int fd);

// CHECK
int		check_lines(char **map);
int		check_path(char **map, int x, int y);
int		check_pos(char **map);
int		check_walls(char **map);
int     check_item(char **map);
int     check_char(char **map);
int		check(char **map);

// INIT
void    init(t_game *game, char *path);

// MAP
char	**init_map(char *path);
void	free_map(char **map);

// PLAYER
void    init_player(t_game *game);

// MOVE
void	change_pos(t_game *game, t_player *pl);

// RENDER
void	put(t_game *g, t_img *img, int x, int y);
int     render(t_game *game);
int     update(t_game *game);

// SPRITES
void    destroy_sprites(t_game *game);
void    init_sprites(t_game *game);

// KEY
int     key(int keycode, t_game *game);

// QUIT
int     quit(t_game *game);

#endif