/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:46:47 by ichougra          #+#    #+#             */
/*   Updated: 2020/12/18 12:56:13 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <math.h>
# include <time.h>
# include "../ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"
# include "get_next_line.h"

# define F file
# define FC color
# define PA path
# define M map
# define PL player
# define R ray
# define D draw
# define K key
# define SP sprite
# define IW imgw
# define DP drawsprite
# define HD hubdraw

typedef struct		s_header
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}					t_header;

typedef struct		s_header2
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_header2;

typedef struct		s_hubdr
{
	int				color;
	int				hmin;
	int				hmax;
	int				wmin;
	int				wmax;
	int				w;
	int				h;
	float			percentw;
	float			percenth;

}					t_hubdr;

typedef struct		s_sprite
{
	float			y;
	float			x;
	float			dist;
	int				perpwalldist;
	int				nb;
	struct s_sprite	*next;

}					t_sprite;

typedef struct		s_imgw
{
	int				*text[8];
	void			*img[8];
	int				width[8];
	int				height[8];
}					t_imgw;

typedef struct		s_draspr
{
	double			inverse;
	double			x;
	double			y;
	int				d;
	int				screen;
	int				start;
	int				end;
	int				height;
	int				width;
	int				drawstartx;
	int				drawstarty;
	int				drawendx;
	int				drawendy;
	int				texx;
	int				texy;
	int				vmovescreen;
	int				color;
}					t_draspr;

typedef struct		s_draw
{
	double			d;
	int				texx;
	int				texy;
	int				start;
	int				end;
	int				lineheight;
}					t_draw;

typedef struct		s_key
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				mvleft;
	int				mvright;
}					t_key;

typedef struct		s_ray
{
	float			sidex;
	float			sidey;
	float			deltdistx;
	float			deltdisty;
	float			raydirx;
	float			raydiry;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	float			perpwalldist;
	int				hit;
	int				side;
}					t_ray;

typedef struct		s_player
{
	char			direction;
	float			y;
	float			x;
	float			plany;
	float			planx;
	float			dirx;
	float			diry;
	float			camx;
	int				pv;
	int				etat;
	int				etatx;
	int				etaty;
}					t_player;

typedef struct		s_map
{
	char			**map;
	char			*mapchar;
	int				width;
	int				height;
}					t_map;

typedef struct		s_path
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
}					t_path;

typedef struct		s_color
{
	int				f1;
	int				f2;
	int				f3;
	int				c1;
	int				c2;
	int				c3;
}					t_color;

typedef struct		s_file
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*imgdata;
	int				axe_x;
	int				axe_y;
	int				save;
	struct s_path	*path;
	struct s_color	*color;
	struct s_map	*map;
	struct s_player	*player;
	struct s_ray	*ray;
	struct s_draw	*draw;
	struct s_key	*key;
	struct s_sprite	*sprite;
	struct s_draspr	*drawsprite;
	struct s_imgw	*imgw;
	struct s_hubdr	*hubdraw;
}					t_file;

void				ft_free_audio(t_file *file);
void				ft_free_sprite(t_file *file);
void				ft_free_fil(t_file *file);
void				ft_sprit_verif_lst(t_file *file);
int					get_next_line(int fd, char **line);
int					ft_l(char const *str);
char				*ft_strjoin(char *s1, char const *s2);
char				*ft_sub(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
int					ft_strcount_char(char *str, char find);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_isdigit(int c);
void				ft_bzero(void *s, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				**ft_split(char const *s, char c);
int					ft_strcmp(char *s1, char *s2);
void				*ft_calloc(size_t count, size_t size);
int					ft_init_color(t_file *file);
int					ft_init_map(t_file *file);
int					ft_init_player(t_file *file);
int					ft_init_path(t_file *file);
int					ft_init_ray(t_file *file);
int					ft_init_draw(t_file *file);
int					ft_init_key(t_file *file);
int					ft_init_imgw(t_file *file);
int					ft_init_hubdraw(t_file *file);
int					ft_init_audio(t_file *file);
int					ft_init_draw_sprite(t_file *file);
t_sprite			*ft_init_sprite(t_file *file, int x, int y, float dist);
int					ft_error_parse(t_file *file, int fd, char *line);
int					ft_verif_color_path(t_file *file);
int					ft_verif_map(t_file *file);
int					ft_verif_reso(t_file *file);
int					ft_verif_player_config(t_file *file, char line, int nb);
int					ft_verif_path_img(t_file *file);
int					ft_start_verif(t_file *file, char **av);
int					ft_parse_cube(char	*fichier, t_file *file);
int					ft_rgbtoint(int red, int green, int blue);
void				ft_move(t_file *file);
int					ft_appui(int i, t_file *file);
int					ft_relache(int i, t_file *file);
void				ft_draw_sprite(t_file *file, int i);
void				ft_draw_hud(t_file *file, int i);
void				ft_readxpm(t_file *file, char *str, int n);
void				ft_hit_wall(t_file *file);
void				ft_draw(t_file *file, int x);
void				raycast(t_file *file);
void				ft_colorchr(char *line, t_file *file, int p, int i);
void				ft_pathchr(char *line, t_file *file, int p);
int					ft_set_line(t_file *file, char *line, int nb, int i);
int					ft_first_line_map(char *line, int i, int nb, t_file *file);
int					ft_config_map(int fd, char *line, t_file *file);
int					ft_config_map2(int i, char *line, t_file *file);
int					ft_join_charmap(t_file *file, char *line, int i, int nb);
int					ft_quit(t_file *file);
void				ft_smile(t_file *file);
int					ft_snakeoil(t_file *file);
int					ft_resochr(char *line, t_file *var);
int					error_main(int ac, char **av);

#endif
