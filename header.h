/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 23:24:20 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/08/28 00:49:59 by kupsyloc         ###   ########.fr       */
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




#endif
