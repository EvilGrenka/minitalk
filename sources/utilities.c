/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:01:56 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/17 13:59:50 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_atoi(const char *str)
{
	int		nbr;
	int		neg;

	nbr = 0;
	neg = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -neg;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * neg);
}

void	ft_putchar_fd(char chr, int fd)
{
	write(fd, &chr, 1);
}

void	ft_putstr_fd(char *msg, int fd)
{
	while (*msg)
		write(fd, msg++, 1);
}

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == INT_MIN)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd('8', fd);
	}
	else if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-nbr, fd);
	}
	else
	{
		if (nbr / 10)
			ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((nbr % 10) + '0', fd);
	}
}

void	print_error_and_exit(char *err_msg)
{
	ft_putstr_fd("Error - ", STDERR_FILENO);
	if (err_msg)
		ft_putstr_fd(err_msg, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_FAILURE);
}
