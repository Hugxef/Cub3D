/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xu8t.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:35:07 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/15 16:29:28 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XU8T_H
# define XU8T_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "/usr/local/include/mlx.h"
# include "../gnl/get_next_line.h"
# define DR 0.0174533

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	delta_x;
	double	delta_y;
	double	angle;
}				t_player;

typedef struct s_map
{
	int		max_x;
	int		max_y;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	int		tile;
	int		*map;
	int		**ddmap;
	char	*map_str;
	int		mal;
}				t_map;

typedef struct s_rays
{
	float	fov;
	float	rays_coef;
	float	loop_offset;
	int		max_x;
	int		max_y;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	int		px;
	int		py;
	int		*i0;
	int		*i1;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float	a_tan;
	float	dist_h;
	float	dist_v;
	float	dist_t;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	int		type;
}				t_rays;

typedef struct s_xpm
{
	char	*path;
	void	*img;
	int		bpp;
	int		size_l;
	int		endian;
	int		x_width;
	int		x_height;
	void	*data;
}				t_xpm;

typedef struct s_draw
{
	float		l_height;
	float		l_offset;
	float		ca;
	int			i;
	int			i0[2];
	int			i1[2];
}				t_draw;

typedef struct s_xu8t
{
	void		*mlx;
	void		*win;
	float		res_x;
	float		res_y;
	void		*img;
	char		*data;
	int			bpp;
	int			size_l;
	int			endian;
	t_player	*t_p;
	t_map		*t_m;
	t_xpm		*nx;
	t_xpm		*sx;
	t_xpm		*ex;
	t_xpm		*wx;
	int			file;
	int			file_bis;
	int			p_pos;
	double		wpi;
	double		epi;
	double		npi;
	double		spi;
}				t_xu8t;

typedef struct s_bres
{
	int	dx;
	int	dy;
	int	dx_x;
	int	dy_x;
	int	ex;
	int	ey;
	int	x_inc;
	int	y_inc;
}	t_bres;

// main.c
void			make_twod_map(t_xu8t *cub);

// xu8t.c
void			xu8t_render(t_xu8t *xu8t);
unsigned int	select_texture(t_xu8t *xu8t, t_rays *r, t_draw *d);
unsigned int	jenny_color(int x, int y, t_xpm *texture, int l_h);
unsigned int	shadow_maker(unsigned int color, float l_h, float res);

// xu8t_utils.c
void			put_pixel(t_xu8t *xu8t, int x, int y, int c);
void			xu8t_draw_line(t_xu8t *xu8t, t_rays *r, t_draw *d);
void			xu8t_bresenham_dv6ted4(t_xu8t *xu8t, int x, int y, int c);
void			xu8t_bresenham_ep6dts(t_xu8t *xu8t, int x, int y, int c);

// xu8t_utils_2.c
void			draw_3d(t_xu8t *xu8t, t_rays *r, int x);
unsigned long	create_rgb(int r, int g, int b, int c);
float			calc_ca(t_xu8t *xu8t, t_rays *r);

// xu8t_utils_3.c
void			xu8t_ceiling(t_xu8t *xu8t);
void			xu8t_floor(t_xu8t *xu8t);
unsigned int	jenny_color(int x, int y, t_xpm *texture, int l_h);

// rays_utils.c
void			rays_init(t_xu8t *xu8t, t_rays *r);
void			rays_angle_calc(t_rays *r, double angle, int mode);
void			horizontal_casting(t_rays *r);
void			vertical_casting(t_rays *r);
void			reset_casting_values(t_rays *r, int mode);

// rays_utils_2.c
void			horizontal_loop(t_rays *r, t_xu8t *xu8t);
void			vertical_loop(t_rays *r, t_xu8t *xu8t);

// rays_calc.c
void			horizontal_calc(t_xu8t *xu8t, t_rays *r);
void			vertical_calc(t_xu8t *xu8t, t_rays *r);
void			select_ray(t_rays *r);
double			dist(float x0, float y0, float x1, float y1);

// xu8t_hooks_move.c
void			xu8t_move_up(t_xu8t *xu8t);
void			xu8t_move_down(t_xu8t *xu8t);
void			xu8t_move_left(t_xu8t *xu8t);
void			xu8t_move_right(t_xu8t *xu8t);

// xu8t_hooks_camera.c
void			xu8t_camera_left(t_xu8t *xu8t);
void			xu8t_camera_right(t_xu8t *xu8t);

// parsing.c
t_xu8t			*create_xu8t(void);
int				check_extension(char *str, char *ext);
void			create_xpm_images(t_xu8t *xu8t);
void			get_player_orientation(t_xu8t *xu8t, char o);
int				get_player_position_x(t_xu8t *xu8t);
int				get_player_position_y(t_xu8t *xu8t);

// parsing_2.c
void			map_str_to_int(t_xu8t *xu8t);
void			check_map(t_xu8t *xu8t, char *line);
int				check_extension(char *str, char *ext);
void			check_texture_open(t_xu8t *xu8t, char *line, t_xpm *texture);
void			check_texture(t_xu8t *xu8t, char *line);

// parsing_3.c
int				get_player_position(t_xu8t *xu8t, int i);
void			str_to_int_loop(t_xu8t *xu8t, int i);
int				check_split(char **split);
void			map_struct(t_xu8t *xu8t);

// parsing_4.c
void			get_map_data(t_xu8t *xu8t);
void			check_walls(t_xu8t *xu8t);
void			select_parser(t_xu8t *xu8t, char *line, char *lenght_tester);
void			check_max_map_len(t_xu8t *xu8t, char *line);
void			check_color(t_xu8t *xu8t, char *line);

// parsing_5.c
int				check_walls_top_bottom(t_xu8t *xu8t);
int				check_walls_left_right(t_xu8t *xu8t);

// ft_isletter.c
int				ft_isletter(char x);

// ft_substr.c
char			*ft_substr(char *str, int x);
int				ft_strlen(char *str);

// ft_split.c
char			**ft_split(char const *s, char c);

// ft_atoi.c
int				ft_atoi(const char *nptr);

// ft_ismapping.c
int				ft_ismapping(char x);

// ft_strdup.c
char			*ft_strdup(char *s);

// xu8t_strjoin.c
char			*xu8t_strjoin(char *s1, char *s2);

// errors.c
int				souris(t_xu8t *xu8t);
void			free_moi_connard(t_xu8t *xu8t);
void			errors_map(t_xu8t *xu8t, int err);
void			errors_malloc(t_xu8t *xu8t);
void			errors_open(t_xu8t *xu8t, int err);

// xu8t_collision.c
int				delta_up(t_xu8t *xu8t, int mode);
int				delta_down(t_xu8t *xu8t, int mode);
int				delta_left(t_xu8t *xu8t, int mode);
int				delta_right(t_xu8t *xu8t, int mode);
void			print_map(t_xu8t *xu8t);

// xu8t_collision_2.c
int				oriented_up_zero(t_xu8t *xu8t);
int				oriented_up_one(t_xu8t *xu8t);
int				oriented_down_zero(t_xu8t *xu8t);
int				oriented_down_one(t_xu8t *xu8t);

// xu8t_collision_3.c
int				oriented_left_zero(t_xu8t *xu8t);
int				oriented_left_one(t_xu8t *xu8t);
int				oriented_right_zero(t_xu8t *xu8t);
int				oriented_right_one(t_xu8t *xu8t);

#endif
