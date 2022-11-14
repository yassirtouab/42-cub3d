/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:27:29 by ytouab            #+#    #+#             */
/*   Updated: 2022/11/14 01:46:28 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	ft_replace_texture(t_all *all, char *direction, int a)
{
	char	*tmp;
	int		i;

	i = 3;
	tmp = NULL;
	if (ft_strncmp(all->textures[a], direction, 3))
		ft_error(all, 10);
	while (all->textures[a][i] == ' ')
		i++;
	tmp = ft_substr(all->textures[a], i, ft_strlen(all->textures[a]));
	if (!tmp)
		return ;
	free(all->textures[a]);
	all->textures[a] = ft_strdup(tmp);
	free(tmp);
}

void	ft_texture(t_all *all)
{
	size_t	i;
	int		rd;

	i = 0;
	rd = 0;
	ft_replace_texture(all, "NO ", 0);
	ft_replace_texture(all, "SO ", 1);
	ft_replace_texture(all, "WE ", 2);
	ft_replace_texture(all, "EA ", 3);
	while (i < 4)
	{
		rd = open(all->textures[i], O_RDONLY);
		if (rd < 0)
			ft_error(all, 10);
		close(rd);
		i++;
	}
}

void	ft_config_sort(t_all *all)
{
	char	**arr;

	arr = ft_arr_dup(all->splmap, 0, 6);
	all->splmap[0] = ft_line_replace(all->splmap[0],
			arr[ft_find_index(all, arr, "NO ", 3)]);
	all->splmap[1] = ft_line_replace(all->splmap[1],
			arr[ft_find_index(all, arr, "SO ", 3)]);
	all->splmap[2] = ft_line_replace(all->splmap[2],
			arr[ft_find_index(all, arr, "WE ", 3)]);
	all->splmap[3] = ft_line_replace(all->splmap[3],
			arr[ft_find_index(all, arr, "EA ", 3)]);
	all->splmap[4] = ft_line_replace(all->splmap[4],
			arr[ft_find_index(all, arr, "F ", 2)]);
	all->splmap[5] = ft_line_replace(all->splmap[5],
			arr[ft_find_index(all, arr, "C ", 2)]);
	ft_free_arr(arr);
}

void	ft_color_parse(t_all *all)
{
	char	*fc;
	char	*cc;

	ft_color_chars_checker(all, 2, 0, 0);
	fc = ft_convert_base(ft_rgb_to_hex(all, all->colors[0], 2), HEX, DEC);
	cc = ft_convert_base(ft_rgb_to_hex(all, all->colors[1], 2), HEX, DEC);
	all->mlx->fcolor = ft_atoi_index(all, fc, 0, 6);
	all->mlx->ccolor = ft_atoi_index(all, cc, 0, 6);
	free(fc);
	free(cc);
}
