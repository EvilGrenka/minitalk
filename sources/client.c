/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:20:06 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/17 14:08:25 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static bool	g_flag_pause;

static void	handler_sig_from_server(int sig)
{
	if (sig == SIGUSR2)
		g_flag_pause = false;
	return ;
}

static void	set_null_character(int pid_server)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_flag_pause = true;
		usleep(50);
		if (kill(pid_server, SIGUSR1) == -1)
			print_error_and_exit("Server not found");
		while (g_flag_pause)
			;
		bit++;
	}
}

static void	send_msg_to_server(char *msg, int pid_server)
{
	int	shift;

	while (*msg)
	{
		shift = 0;
		while (shift < 8)
		{
			usleep(50);
			g_flag_pause = true;
			if ((*msg >> shift) & 1)
			{
				if (kill(pid_server, SIGUSR2) == -1)
					print_error_and_exit("Server not found");
			}
			else
				if (kill(pid_server, SIGUSR1) == -1)
					print_error_and_exit("Server not found");
			while (g_flag_pause)
				;
			shift++;
		}
		msg++;
	}
	set_null_character(pid_server);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		print_error_and_exit("Wrong number of arguments! Pls Try again.");
	signal(SIGUSR2, handler_sig_from_server);
	send_msg_to_server(argv[2], ft_atoi(argv[1]));
	return (0);
}
