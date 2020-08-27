#include "header.h"

void print_map(t_fdf *fdf)
{
	int i[2];
	i[0] = 0;
	i[1] = 0;
	while (i[0] != fdf->height)
	{
		printf("\n");
		while (i[1] != fdf->width)
		{
			ft_printf("%3d", fdf->matrix[i[0]][i[1]]);
			i[1]++;
		}
		i[1] = 0;
		i[0]++;
	}
}




int *spliter(char *str, t_fdf *fdf)
{
	static	int line;
	int		i;
	char	**buff;

	i = 0;
	buff = ft_strsplit(str, ' ');
	if (fdf->width == 0)
		while (buff[fdf->width])
			fdf->width++;
	fdf->matrix[line] = malloc(sizeof(int) * fdf->width);
	while (i != fdf->width)
	{
		// ft_printf("\nmatrix[%d][%d] = %d", line, i,ft_atoi(buff[i]));
		fdf->matrix[line][i++] = ft_atoi(buff[i]);
	}

	



	ft_printf("\n[spliter[i = %d]]Get str %s to line[%d]", fdf->width, str, line);
	line++;
	return NULL;
}

int get_width(char *file, t_fdf *fdf)
{
	int fd;
	int line;
	char *buff;

	fd = open(file, O_RDONLY, 1);
	line = 0;
	while (get_next_line(fd, &buff))
	{
		spliter(buff, fdf);
	}
}





int **map_parser(int argc, char **argv, t_fdf *fdf)
{
    if (argc < 2 || argc > 3)
        return (NULL);
    get_height(argv, fdf);
    ft_printf("\n[map_parser][%d]Argv = %s", argc, argv[1]);
}

int get_height(char **argv, t_fdf *fdf)
{
	int fd;
	char *buff;

	fdf->height = 0;
	fd = open(argv[1], O_RDONLY, 0);
	while (get_next_line(fd,&buff))
		fdf->height++;
	free(buff);
	fdf->width = 0;
	fdf->matrix = (int **)malloc(sizeof(int *) * fdf->height);
	get_width(argv[1], fdf);
	// ft_printf("\n[Height] = %d", fdf->height);
}
