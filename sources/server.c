/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:30:57 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/17 14:03:19 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	put_character(unsigned char new_bit)
{
	static int				shift = 0;
	static unsigned char	character = 0;

	character |= (new_bit) << shift++;
	if (shift > 7)
	{
		if (character == '\0')
		{
			write(1, "\n", 1);
			write(1, &character, 1);
		}
		else
			write(1, &character, 1);
		shift = 0;
		character = 0;
	}
}

static void	get_sig_make_action(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		put_character(0);
	else if (sig == SIGUSR2)
		put_character(1);
	if (kill(info->si_pid, SIGUSR2) == -1)
		print_error_and_exit("Client not found.");
}

int	main(void)
{
	int					pid_server;
	struct sigaction	handler_parameters;

	pid_server = getpid();
	ft_putstr_fd("PID Server: \033[1m\033[30m", STDOUT_FILENO);
	ft_putnbr_fd(pid_server, STDOUT_FILENO);
	ft_putstr_fd("\033[0m\n", STDOUT_FILENO);
	handler_parameters.sa_flags = SA_SIGINFO;
	handler_parameters.sa_sigaction = get_sig_make_action;
	if (sigemptyset(&handler_parameters.sa_mask) == -1)
		print_error_and_exit("Failure to initialize a set of signals.");
	if (sigaddset(&handler_parameters.sa_mask, SIGUSR1) == -1)
		print_error_and_exit("Failure to add signal SIGUSR1.");
	if (sigaddset(&handler_parameters.sa_mask, SIGUSR2) == -1)
		print_error_and_exit("Failure to add signal SIGUSR2.");
	sigaction(SIGUSR1, &handler_parameters, NULL);
	sigaction(SIGUSR2, &handler_parameters, NULL);
	while (42)
		pause();
	return (0);
}
