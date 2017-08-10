/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 10:48:38 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/10 12:00:12 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <libft.h>
# include <draw.h>
# include <mlx.h>
# include <math.h>
# include <OpenCL/opencl.h>

# define WIDTH 1800
# define HEIGHT 1000
# define SIZE_IMG WIDTH * HEIGHT
# define ABS(x) (x < 0 ? -x : x)

# define COLOR1 0xcf0b3e
# define COLOR2 0x074dee
# define COLOR3 0xeeec0e
# define COLOR4 0x09ab14
# define COLORSK 0x4f98e3
# define COLORGR 0x4e310b

typedef struct			s_poz
{
	double		x;
	double		y;
}						t_poz;

typedef struct			s_int
{
	int			x;
	int			y;
}						t_int;

typedef struct			s_mlxo
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*pxl;
	int			bpp;
	int			s_line;
	int			ed;
}						t_mlxo;

typedef struct			s_env
{
	t_mlxo				mlx;
	float				zoom;
	void				(*f)(struct s_env *);
	t_pos				mouse;
	t_poz				pos;
	t_poz				dir;
	t_poz				pl;
	t_poz				cam;
	t_poz				raypos;
	t_poz				raydir;
	t_int				map;
	t_poz				side;
	t_poz				delta;
	int					hit;
	t_poz				step;
	int					hit_side;
	int					**worldmap;
	int					dist;
	int					z;
	int					colornb;
	int					color1;
	int					color2;
	int					color3;
	int					color4;
	int					colorsky;
	int					colorground;
	int					s_line;
}						t_env;

int						main(void);
int						kill_program(t_env *e);
t_env					*init_env(t_env *e);
void					raycasting(t_env *e);
void					draw_line(t_env *e, int x, int start, int end);

#endif
