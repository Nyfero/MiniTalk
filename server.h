/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:30:53 by gsap              #+#    #+#             */
/*   Updated: 2021/07/27 15:49:19 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>

void	handle_sigusr(int sig);
int		main(void);

void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_recursive_power(int nb, int power);
int		ft_bin_to_dec(char *s);
void	ft_print_id_server(void);

#endif
