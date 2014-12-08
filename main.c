/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 14:00:56 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/08 16:25:56 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>
#include <sys/termios.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <termios.h>
#include <fcntl.h>
#include <time.h>
#include "snake.h"

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}

int		getarrowkey(void)
{
	struct termios        line_police;
	char                  c;

	if (ioctl(0, TIOCGETA, &line_police) < 0)
	{
		perror("Oh oh");
		exit(1);
	}
	if (line_police.c_lflag &=  ~(ICANON | ECHO))
	if ((ioctl(0, TIOCSETA, &line_police)) < 0)
	{
		perror("Oh, oh");
		exit(2);
	}
	if(kbhit())
	{
		while ((c = fgetc(stdin)))
		{
			if(c == 68)
			{
				return (1);
			}
			if(c == 65)
			{
				return (2);
			}
			if(c == 66)
			{
				return (3);
			}
			if(c == 67)
			{
				return (4);
			}
		}
	}
	return (0);
}

int rand_a_b(int a, int b)
{
    return rand()%(b-a) + a;
}

/*
 * Main d;exemple pour comprendre le fonctionnement de getarrowkey
 */
int		main(void)
{
	int key;
	while (1)
	{
		ft_putstr("nombre genere : ");
		ft_putnbr(rand_a_b(0, 10));
		key = getarrowkey();
		ft_putstr("\nKEY = ");
		if (key == 1)
			ft_putendl("LEFT");
		else if (key == 2)
			ft_putendl("UP");
		else if (key == 3)
			ft_putendl("DOWN");
		else if (key == 4)
			ft_putendl("RIGHT");
		else
			ft_putendl("nothing");
		usleep(100000);
		system("CLEAR");
	}
	return (0);
}
