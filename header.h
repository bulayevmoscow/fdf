/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 23:24:20 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/08/28 02:31:50 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "minilibx/mlx.h"
#include "libft/ft_printf/includes/header.h"
#include "libft/get_next_line/get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_fdf
{
	int		width;
	int		height;
	int		**matrix;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

int get_height(char **argv, t_fdf *fdf);


#endif

// gcc  -lmlx -framework OpenGL -framework AppKit main.c minilibx/libmlx_intel-mac.a libft/libft_pro.a parser.c -o kekw && ./kekw ./test_maps/42.fdf
