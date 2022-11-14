/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:35:07 by ytouab            #+#    #+#             */
/*   Updated: 2022/11/10 22:55:40 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	ft_checker(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (1);
	while (base[i])
	{
		j = 0;
		while (base[j])
			if (base[i] == base[j++] && i != j - 1)
				return (2);
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\f' || base[i] == '\n' || base[i] == '\t'
			|| base[i] == '\v')
			return (3);
		i++;
	}
	return (0);
}

int	ft_inbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
		if (base[i++] == c)
			return (0);
	return (1);
}

int	ft_lnbr(int nbr, int base_lenght)
{
	int	x;
	int	pbase;

	if (nbr == 0)
		return (1);
	x = 1;
	pbase = 1;
	while (x <= nbr)
	{
		x = x * base_lenght;
		pbase++;
	}
	return (pbase - 1);
}

char	*ft_char(char *dest, char src)
{
	unsigned int	i;

	i = 0;
	while (dest[i])
		i++;
	dest[i++] = src;
	dest[i] = '\0';
	return (dest);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	i;
	int	j;
	int	fnb;
	int	sign;

	i = 0;
	fnb = 0;
	sign = 0;
	if (ft_checker(base_from) != 0 || ft_checker(base_to))
		return (0);
	while (nbr[i] && (nbr[i] == ' ' || nbr[i] == '\f'
			|| nbr[i] == '\n' || nbr[i] == '\t' || nbr[i] == '\v'))
		i++;
	while (nbr[i] && (nbr[i] == '+' || nbr[i] == '-'))
		if (nbr[i++] == '-')
			sign++;
	while (nbr[i] && ft_inbase(nbr[i], base_from) == 0)
	{
		j = 0;
		while (base_from[j])
			if (base_from[j++] == nbr[i])
				fnb = fnb * ft_strlen(base_from) + j - 1;
		i++;
	}
	return (ft_put_nbr(fnb, base_to, sign, -1));
}
