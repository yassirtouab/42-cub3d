/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:53:04 by ytouab            #+#    #+#             */
/*   Updated: 2022/11/14 01:40:52 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

char	*ft_strdup(const char *str)
{
	char	*ret;
	int		i;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	ret = (char *)malloc((i + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (i < (int)ft_strlen(str) && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

size_t	ft_delimiter(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

size_t	ft_wordcount(char *str)
{
	size_t	nb;
	size_t	i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_delimiter(str[i]))
			i++;
		if (str[i] && !ft_delimiter(str[i]))
			nb++;
		while (str[i] && !ft_delimiter(str[i]))
			i++;
	}
	return (nb);
}

char	**ft_split(char *str, t_all *all)
{
	char	**ret;
	size_t	wordc;
	size_t	i;
	size_t	x;

	wordc = ft_wordcount(str);
	ret = (char **)malloc((wordc + 1) * sizeof(char *));
	if (!ret)
		ft_error(all, 4);
	i = 0;
	while (i < wordc)
	{
		while (*str && ft_delimiter(*str))
			str++;
		x = 0;
		while (str[x] && !ft_delimiter(str[x]))
			x++;
		ret[i] = (char *)malloc(x + 1);
		x = 0;
		while (*str && !ft_delimiter(*str))
			ret[i][x++] = *str++;
		ret[i++][x] = 0;
	}
	ret[i] = NULL;
	return (ret);
}

int	ft_find_index(t_all *all, char **arr, char *s, size_t size)
{
	int	i;

	i = 0;
	if (!arr)
		ft_error(all, 5);
	while (arr[i] && i < 6)
	{
		if (!ft_strncmp(arr[i], s, size))
			return (i);
		i++;
	}
	ft_error(all, 5);
	return (i);
}
