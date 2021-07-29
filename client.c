/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:15:53 by gsap              #+#    #+#             */
/*   Updated: 2021/07/29 11:49:05 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	ft_send_msg(argv[2], pid);
	ft_send_msg("\n", pid);
	return (0);
}
