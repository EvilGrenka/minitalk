/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:43:19 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/17 13:55:14 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
# include <stdbool.h>

int		ft_atoi(const char *str);
void	ft_putchar_fd(char chr, int fd);
void	ft_putstr_fd(char *msg, int fd);
void	ft_putnbr_fd(int nbr, int fd);
void	print_error_and_exit(char *err_msg);

#endif