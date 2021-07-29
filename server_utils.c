/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:15:53 by gsap              #+#    #+#             */
/*   Updated: 2021/07/29 11:47:48 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power > 1)
		nb *= ft_recursive_power(nb, power - 1);
	return (nb);
}

int	ft_bin_to_dec(char *s)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '1')
			res += ft_recursive_power(2, (7 - i));
		i++;
	}
	return (res);
}
