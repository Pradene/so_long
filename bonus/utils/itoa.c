/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:31:27 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/01 18:31:29 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count(int n)
{
	int	len;
	int	on;

	on = 1;
	len = 0;
	if (n < 0)
		len++;
	while (n || on)
	{
		on = 0;
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*a;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = n;
	if (n < 0)
		i = -n;
	len = count(n);
	a = malloc(sizeof(char) + (len + 1));
	if (!a)
		return (NULL);
	a[len] = '\0';
	if (!n)
		a[0] = '0';
	else if (n < 0)
		a[0] = '-';
	while (i > 0)
	{
		--len;
		a[len] = i % 10 + '0';
		i = i / 10;
	}
	return (a);
}
