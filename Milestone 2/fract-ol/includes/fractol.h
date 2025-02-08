
#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../Libft/includes/libft.h"
# include <math.h>
# include <X11/keysym.h>
#include <time.h>
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000
# define DEFAULT_ZOOM 1
# define ZOOM_FACTOR 1.08
# define ZOOM_MAX 3764317556241755.0
# define ZOOM_MIN 0.01
# define PRECISION_FACTOR 5
# define MOVE_FACTOR 0.1
# define INSIDE_COLOR 0x000000
# define DEFAULT_ITERATIONS 30
# define ESCAPE_LIMITE 4.0
# define PALETTE_SIZE 13

enum e_sets
{
	Mandelbrot_square,
	Mandelbrot_cube,
	Julia_square,
	Julia_cube,
	Burningship_square,
	Burningship_cube,
};

enum e_events_hooks
{
	ON_MOUSEMOVE = 6,
	ON_DESTROY = 17,
};

enum e_events_inputs
{
	INCREASE_BUTTON = 1,
	DECREASE_BUTTON = 3,
	ZOOM_IN = 4,
	ZOOM_OUT = 5,
	LEFT_KEY = 65361,
	UP_KEY = 65362,
	RIGHT_KEY = 65363,
	DOWN_KEY = 65364,
	ESCAPE_KEY = 65307,
	PLUS_KEY = 65451,
	MINUS_KEY = 65453,
	SHIFT_KEY = 65505,
	SPACE_KEY = 32,
};

typedef struct s_rgb
{
	int		r;
	int		g; // 8

	double	percent; // 8
	
	int		b;
	int		index1; // 8

	int		index2;
	int		color1; // 8


	double	scaled_percent; // 8
	
	double	fractional; // 8

	int		color2;
}				t_rgb;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_complex
{
	double	re;
	double	img;
}				t_complex;

typedef struct s_cor
{
	double		x;
	double		y;
}				t_cor;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_cor	center;
	t_img	img;
	int		set_type;
	double	min_re;
	double	max_re;
	double	min_img;
	double	max_img;
	double	re_factor;
	double	img_factor;
	double	zoom;
	int		zoom_target_x;
	int		zoom_target_y;
	int		precision;
	double	fixed_c_re;
	double	fixed_c_img;
	t_bool	trick_mouse;
	int		palette[PALETTE_SIZE];
}				t_fractol;

// Parsing
t_bool		ft_check_set_arg(char *set, char *set_arg, char *power, char *power_arg);
void		ft_check_parse(t_fractol *fractol, int ac, char **av);

// Struct Utils
void		ft_init_fractol(t_fractol *fractol);
void		ft_init_image_buffer(t_fractol *fractol);
void		ft_clean_fractol(t_fractol *fractol);
int			ft_close(t_fractol *fractol);

// Events Hook
int			ft_mouse_hook(int button, int x, int y, t_fractol *fractol);
int			ft_key_hook(int keycode, t_fractol *fractol);
int			ft_mouse_move_hook(int x, int y, t_fractol *fractol);

// 2D logical plane Utils
void		ft_init_complex_plan(t_fractol *fractol);
t_complex	ft_map_to_complex(t_fractol *fractol, int x, int y);
void		ft_zoom_plan(t_fractol *fractol, double zoom_factor, int mouse_x, int mouse_y);
void		ft_move_plan(t_fractol *fractol, double offset_x, double offset_y);


// Draw functions
void		ft_draw_fractal(t_fractol *fractol);
void		ft_walk(t_fractol *fractol, int (*fractal_func)(t_fractol *, t_complex));

// Fractal Sets Equations
int			ft_mandelbrot_sq_set(t_fractol *fractol, t_complex c);
int			ft_mandelbrot_cub_set(t_fractol *fractol, t_complex c);
int			ft_julia_sq_set(t_fractol *fractol, t_complex c);
int			ft_julia_cub_set(t_fractol *fractol, t_complex c);
int			ft_burningship_sq_set(t_fractol *fractol, t_complex c);
int			ft_burningship_cub_set(t_fractol *fractol, t_complex c);

// Fractol Utils
int			ft_abs(int nbr);
void		ft_my_optimized_pixel_put(t_fractol *fractol, t_img *img, int x, int y, int color);
void		ft_generate_random_gradient_color(t_fractol *fractol);
int			ft_get_psychedelic_color(t_fractol *fractol, int iter);

// Others
int			ft_loop_hook(t_fractol *fractol);

#endif
