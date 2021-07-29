/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:15:53 by gsap              #+#    #+#             */
/*   Updated: 2021/07/29 11:48:11 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_atoi(const char *str)
{
	int	j;
	int	res;

	j = 1;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			j *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - 48);
	return ((res * j));
}

char	*ft_itoa(int n)
{
	int		nb;
	int		i;
	char	*str;

	nb = n;
	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = 0;
	i--;
	while (i >= 0)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_dec_to_bin(int n)
{
	char	*bin;
	char	*base;
	int		i;

	base = "01";
	bin = (char *)malloc(sizeof(char) * 9);
	if (!bin)
		return (NULL);
	bin[8] = 0;
	i = 7;
	while (i >= 0)
	{
		bin[i] = base[(n % 2)];
		n = (n / 2);
		i--;
	}
	return (bin);
}
