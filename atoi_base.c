/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 13:43:02 by opariy            #+#    #+#             */
/*   Updated: 2018/07/05 13:43:08 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	stepen(int n, int stepen)
{
	int result;

	result = n;
	if (stepen == 0)
		return (1);
	while (--stepen > 0)
		result = result * n;
	return (result);
}

static char	worker(char c)
{
	int result;

	result = 0;
	if (c > 47 && c < 58)
		result = c - 48;
	else if (c > 64 && c < 71)
		result = c - 55;
	else if (c > 96 && c < 103)
		result = c - 87;
	return (result);
}

int			ft_atoi_base(char *str, int base)
{
	int result;
	int c;
	int m;
	int sign;

	result = 0;
	m = ft_strlen(str);
	c = -1;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		c = c + 1;
		m--;
	}
	if (str[c + 1] == 'x' || str[c + 1] == 'X' || str[c + 2] == 'x' ||
		str[c + 2] == 'X')
	{
		c = c + 2;
		m = m - 2;
	}
	while (str[++c] != '\0')
		result = result + (worker(str[c]) * stepen(base, --m));
	return (result * sign);
}
