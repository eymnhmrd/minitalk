/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:42:59 by ahamrad           #+#    #+#             */
/*   Updated: 2023/03/24 00:40:35 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_kill_error(void)
{
	ft_putstr("Error in kill");
	exit(EXIT_FAILURE);
}

void	ft_send_char(int pid, char c)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_kill_error();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_kill_error();
		}
		i++;
		usleep(1200);
		c = c >> 1;
	}
}

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*str;
	int		i;

	if (argc != 3)
	{
		ft_putstr("Usage : ./client [pid] [string-to-send]\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr("PID cannot be negative !!\n");
		exit(EXIT_FAILURE);
	}
	str = argv[2];
	i = 0;
	while (str[i])
	{
		ft_send_char(server_pid, str[i]);
		i++;
	}
	ft_send_char(server_pid, '\n');
	return (0);
}
