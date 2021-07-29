/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:15:53 by gsap              #+#    #+#             */
/*   Updated: 2021/07/29 11:46:58 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	g_c;

void	id_process(void)
{
	int	i;

	i = getpid();
	write(1, "PID Server: ", 12);
	ft_putnbr(i);
	write(1, "\n", 1);
	return ;
}

void	handle_sigusr(int sig)
{
	if (sig == SIGUSR1)
		g_c = '0';
	if (sig == SIGUSR2)
		g_c = '1';
}

int	main(void)
{
	char	s[9];
	int		i;

	i = 0;
	id_process();
	if (signal(SIGUSR1, handle_sigusr) != 0)
		return (0);
	if (signal(SIGUSR2, handle_sigusr) != 0)
		return (0);
	while (1)
	{
		pause();
		s[i++] = g_c;
		if (i == 8)
		{
			ft_putchar((char)ft_bin_to_dec(s));
			s[i] = 0;
			i = 0;
		}
	}
	return (0);
}
