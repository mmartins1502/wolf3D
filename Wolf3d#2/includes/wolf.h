/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 10:48:38 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/23 15:08:18 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <libft.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 1200
# define HEIGHT 800

# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2

# define COLOR1 0xD8E1DF
# define COLOR2 0xAEB5B4
# define COLOR3 0xA1A5A4
# define COLOR4 0x93918E
# define COLORSK 0x2D241E
# define COLORGR 0x606060

# define COLOR5 0x00046B
# define COLOR6 0x00058A
# define COLOR7 0x040AAB
# define COLOR8 0x0F15C3
# define COLORSK1 0x4C4C4F
# define COLORGR1 0x878787

typedef struct			s_int
{
	int					x;
	int					y;
}						t_int;

typedef struct			s_double
{
	double				x;
	double				y;
}						t_double;

typedef struct			s_player
{
	t_double			pos;
	t_double			dir;
	t_double			pl;
	int					z;
	double				speed_move;
	double				speed_turn;
	int					jump;
	int					sprint;
}						t_player;

typedef struct			s_ray
{
	t_double			pos;
	t_double			dir;
	t_int				map;
	t_double			side;
	t_double			delta;
	t_double			step;
	double				dist;
	double				cam;
	int					hit;
	int					hit_side;
}						t_ray;

typedef struct			s_mlxo
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*pxl;
	int					bpp;
	int					s_line;
	int					ed;
}						t_mlxo;

typedef struct			s_env
{
	t_player			play;
	t_ray				ray;
	t_mlxo				mlx;
	int					width;
	int					height;
	int					map_width;
	int					map_height;
	int					**map;
	unsigned int		color1;
	unsigned int		color2;
	unsigned int		color3;
	unsigned int		color4;
	unsigned int		color_sky;
	unsigned int		color_ground;
	int					mapnb;
	char				**texture;
	t_mlxo				*text;
	int					weapon;
	int					enter;
	int					mapon;
	int					select;
	int					wallcolor;
	int					mouse;
}						t_env;

int						main(int ac, char **av);
int						ft_free(t_env *e);
int						init_env(t_env *e);
int						key_hook_1(int keycode, t_env *e);
int						map(t_env *e);
void					raycasting(t_env *e);
void					draw_line(t_env *e, int x, int start, int end);
int						loop_hook(t_env *e);
void					key_move(int keycode, t_env *e);
int						key_press(int keycode, t_env *e);
int						key_hook_2(int keycode, t_env *e);
void					set_menu(t_env *e);
void					homescreen(t_env *e);
void					draw_minimap(t_env *e);
void					move_left(t_env *e);
void					move_right(t_env *e);
int						e_mouse_move(int x, int y, t_env *e);

#endif
