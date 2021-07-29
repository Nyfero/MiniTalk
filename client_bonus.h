/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:15:32 by gsap              #+#    #+#             */
/*   Updated: 2021/07/29 18:40:46 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>

void	ft_handle_sigusr(int sig);
char	*ft_dec_to_bin(unsigned int n);
void	ft_send_msg(char *s, int pid);
int		main(int argc, char **argv);

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);

#endif
