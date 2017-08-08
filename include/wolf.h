/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:48:38 by mmartins          #+#    #+#             */
/*   Updated: 2017/06/16 17:55:03 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <libft.h>
# include <draw.h>
# include <mlx.h>
# include <math.h>
# include <OpenCL/opencl.h>

# define WIDTH 1300
# define HEIGHT 1300
# define HT_WALL 10
# define POSX 5.5
# define POSY 5.5
# define HT_CAM HT_WALL / 2
# define SIZE_IMG WIDTH * HEIGHT
# define ABS(x) (x < 0 ? -x : x)

typedef struct			s_opencl
{
	size_t				workGroupSize;
	cl_platform_id		platform_id;
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	commands;
	cl_program			program;
	cl_kernel			kernel;
	cl_event			event;
	cl_mem				img_mem;
	int					*img;
}						t_opencl;

typedef struct			s_play
{
	
}						t_play;

typedef struct			s_env
{
	t_mlx				*mlx;
	float				zoom;
	void				(*f)(struct s_env *);
	t_pos				mouse;
	t_opencl			opencl;
}						t_env;

int						main(int ac, char **av);
int						kill_program(t_env *e);
t_env					*init_env(t_env *e);

#endif
