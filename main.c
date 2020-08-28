#include "header.h"
#include <stdio.h>

void bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float x_step;
	float y_step;
	int max;

	x_step = x1 - x;
	y_step = y1 - y;

	max = MAX(ABS(x_step), ABS(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1))
	{
		// mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}
	for (int i = 0; i < 500; i++)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, i, 0xffffff);
	}
}


int main(int argc, char **argv)
{
    int **test;
	t_fdf *fdf;
	fdf = (t_fdf*)malloc(sizeof(t_fdf));

	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "KEKW");
	
	// bresenham(20, 20, 50, 50, fdf);

	for (int i = 0; i < 500; i++)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, i, i, 0xffffff);
	}
		mlx_loop(fdf->mlx_ptr);
	print_map(fdf);
	// map_parser(argc, argv, fdf);
	// ft_printf("kekw %d", fdf->matrix[3][3]);
    ft_printf("\ndone");
    return (2);
}
