#include "header.h"
#include <stdio.h>




int main(int argc, char **argv)
{
    int **test;
	t_fdf *fdf;
	fdf = (t_fdf*)malloc(sizeof(t_fdf));
	map_parser(argc, argv, fdf);
	print_map(fdf);
	// ft_printf("kekw %d", fdf->matrix[3][3]);
    ft_printf("\ndone");
    return (2);
}
