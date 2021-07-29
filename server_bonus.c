/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:15:53 by gsap              #+#    #+#             */
/*   Updated: 2021/07/29 18:44:12 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

static unsigned int	g_int;

int	ft_send_it_back(int j)
{
	static char	s[7];

	if (!g_int)
		j++;
	else
	{
		s[j++] = (char)g_int;
		if (j == 5)
		{
			s[j] = 0;
			write(1, "\n>>> End of message from ", 25);
			ft_putstr(s);
			write(1, "<<<\n", 4);
			kill(ft_atoi(s), SIGUSR1);
			j = -1;
		}
	}
	return (j);
}

void	ft_handle_sigusr(int sig)
{
	static int	i = 7;
	static int	j = -1;

	if (sig == SIGUSR2)
		g_int |= (1 << i);
	i--;
	if (i < 0)
	{
		if (!g_int || j >= 0)
			j = ft_send_it_back(j);
		else
			ft_putchar(g_int);
		g_int = 0;
		i = 7;
	}
	return ;
}

void	ft_print_id_server(void)
{
	int	i;

	i = getpid();
	write(1, "PID Server: ", 12);
	ft_putnbr(i);
	write(1, "\n", 1);
	return ;
}

int	main(void)
{
	g_int = 0;
	ft_print_id_server();
	if (signal(SIGUSR1, ft_handle_sigusr) != 0)
		return (0);
	if (signal(SIGUSR2, ft_handle_sigusr) != 0)
		return (0);
	while (1)
		pause();
	return (0);
}
