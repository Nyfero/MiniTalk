/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:15:32 by gsap              #+#    #+#             */
/*   Updated: 2021/07/27 13:29:29 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>

int		main(int argc, char **argv);

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_dec_to_bin(int n);
void	ft_send_msg(char *s, int pid);

#endif
