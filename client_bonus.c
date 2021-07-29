/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:15:23 by gsap              #+#    #+#             */
/*   Updated: 2021/07/29 18:44:26 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	ft_handle_sigusr(int sig)
{
	(void)sig;
	write(1, ">>> Message send <<<\n", 22);
}

char	*ft_dec_to_bin(unsigned int n)
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

void	ft_send_msg(char *s, int pid)
{
	int		i;
	int		j;
	char	*bin;

	i = 0;
	while (s[i])
	{
		j = 0;
		bin = ft_dec_to_bin(s[i]);
		if (!bin)
			return ;
		while (bin[j])
		{
			if (bin[j] == '0')
				kill(pid, SIGUSR1);
			else if (bin[j] == '1')
				kill(pid, SIGUSR2);
			j++;
			usleep(150);
		}
		free(bin);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	int		i;

	if (argc != 3)
		return (1);
	if (signal(SIGUSR1, ft_handle_sigusr) != 0)
		return (0);
	server_pid = ft_atoi(argv[1]);
	ft_send_msg(argv[2], server_pid);
	i = 0;
	while (i < 8)
	{
		kill(server_pid, SIGUSR1);
		usleep(150);
		i++;
	}
	ft_send_msg(ft_itoa(getpid()), server_pid);
	return (0);
}
