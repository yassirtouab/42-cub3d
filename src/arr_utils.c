/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:23:00 by ytouab            #+#    #+#             */
/*   Updated: 2022/11/14 01:24:48 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

size_t	ft_arr_len(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

void	ft_arr_print(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		ft_putstr_fd(arr[i++], 1);
		ft_putstr_fd("\n", 1);
	}
}

char	**ft_arr_dup(char **arr, size_t start, size_t size)
{
	size_t	i;
	size_t	j;
	char	**ret;

	if (!size)
		return (NULL);
	i = start;
	j = 0;
	ret = (char **)malloc((size + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	while ((i < (start + size)) && arr[i])
		ret[j++] = ft_strdup(arr[i++]);
	ret[j] = NULL;
	return (ret);
}

void	ft_free_arr(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr[i]);
	free(arr);
}

char	*ft_line_replace(char *old, char *new)
{
	if (!new)
		return (NULL);
	if (old)
	{
		free(old);
		old = NULL;
	}
	return (ft_strdup(new));
}
