/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:26:12 by isaad             #+#    #+#             */
/*   Updated: 2022/11/13 18:15:12 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	mlx_struct_init(t_mlx *mlx, t_size *size, t_all *all)
{
	ft_bzero(size, sizeof(t_size));
	ft_bzero(mlx, sizeof(t_mlx));
	ft_bzero(all, sizeof(t_all));
	all->mlx = mlx;
	size->posx = 3;
	size->posy = 27;
	direction(size);
	size->win_x = 960;
	size->win_y = 540;
	all->size = size;
}

void	initdrawing(t_all *all, int x)
{
	all->size->camerax = 2 * x / (double)all->size->win_x - 1;
	all->size->raydirx = all->size->dirx + all
		->size->planex * all->size->camerax;
	all->size->raydiry = all->size->diry + all->size
		->planey * all->size->camerax;
	all->size->mapx = (int)all->size->posx;
	all->size->mapy = (int)all->size->posy;
	if (all->size->raydirx == 0)
		all->size->deltadistx = 1e30;
	else
		all->size->deltadistx = fabs(1 / all->size->raydirx);
	if (all->size->raydiry == 0)
		all->size->deltadisty = 1e30;
	else
		all->size->deltadisty = fabs(1 / all->size->raydiry);
	all->size->hit = 0;
}

void	extra_imgs(t_all *all)
{
	all->mlx->tex3 = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[2], &all->mlx->w, &all->mlx->h);
	all->mlx->text3 = (int *)mlx_get_data_addr(all->mlx->tex3,
			&all->mlx->b, &all->mlx->h, &all->mlx->w);
	all->mlx->tex4 = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[3], &all->mlx->w, &all->mlx->h);
	all->mlx->text4 = (int *)mlx_get_data_addr(all->mlx->tex4,
			&all->mlx->b, &all->mlx->h, &all->mlx->w);
	all->mlx->tex5 = mlx_xpm_file_to_image(all->mlx->mlx, \
		"Imgs/gun.xpm", &all->mlx->w, &all->mlx->h);
	all->mlx->tex6 = mlx_xpm_file_to_image(all->mlx->mlx, \
		"Imgs/gunshoot.xpm", &all->mlx->w, &all->mlx->h);
}

int	mouse_hook(int keycode, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (keycode == 1 && all->flag == 0 && y > 0)
	{
		all->flag = 1;
		print_plz(all, all->map);
	}
	else if (y > 0)
	{
		all->flag = 0;
		print_plz(all, all->map);
	}
	return (0);
}

void	draw_sprites(t_all *all)
{
	if (all->flag == 0)
		mlx_put_image_to_window(all->mlx->mlx,
			all->mlx->mlx_win, all->mlx->tex5, all->size->\
				win_x / 2, all->size->win_y / 2);
	if (all->flag == 1)
		mlx_put_image_to_window(all->mlx->mlx,
			all->mlx->mlx_win, all->mlx->tex6, all->\
				size->win_x / 2, all->size->win_y / 2);
}
