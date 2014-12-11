/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 22:57:11 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/11 15:48:08 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "snake.h"
#include <stdlib.h>

#define BLUE ft_putstr("\033[1;34m")

#define BLANC ft_putstr("\033[0;02m")

#define VERT ft_putstr("\033[1;32m")
#define RED ft_putstr("\033[1;31m")
void	set_tab(int **tab, int w, int h)
{
	int i = 0;
	int j;
	while (i < w)
	{
		tab[i][0] = ELEM_DIESE;
		tab[i][h - 1] = ELEM_DIESE;
		i++;
	}
	i = 0;
	while (i < h)
	{
		tab[0][i] = ELEM_DIESE;
		tab[w - 1][i] = ELEM_DIESE;
		i++;
	}
	i = 1;
	while (i < w - 1)
	{
		j = 1;
			while (j < h -1)
			{
				tab[i][j] = ELEM_VOID;
				j++;
			}
		i++;
	}
}

void	puttab(int **tab, int w, int h)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (tab[x][y] == ELEM_DIESE)
			{
				BLUE;
				ft_putstr("#");
				BLANC;
			}
			else if (tab[x][y] == ELEM_VOID)
				ft_putchar(' ');
			else if (tab[x][y] == ELEM_SNAKE)
			{
				VERT;
				ft_putchar('s');
				BLANC;
			}
			else if (tab[x][y] == ELEM_APPLE)
			{
				RED;
				ft_putchar('a');
				RED;
			}
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void		*snakeadd(t_snake *snake, int posx, int posy)
{
	t_snake *new_end;

	new_end = (t_snake *)malloc(sizeof(t_snake));
	new_end->pos.x = posx;
	new_end->pos.y = posy;
	new_end->mom = snake->end2;
	snake->end2->next = new_end;
	snake->end2 = new_end;
}

int		updatetab(int **tab, int dir, t_snake *snake, t_point *apple, int w ,int h)
{
	t_snake *tmp;
	int x_end;
	int y_end;

	x_end = snake->end2->pos.x;
	y_end = snake->end2->pos.y;
	tmp = snake->end2;
	tab[snake->end2->pos.x][snake->end2->pos.y] = ELEM_VOID;
	while (tmp->mom)
	{
		tmp->pos.x = tmp->mom->pos.x;
		tmp->pos.y = tmp->mom->pos.y;
		tmp = tmp->mom;
	}
		if (dir == LEFT)
			snake->pos.x--;
		if (dir == RIGHT)
			snake->pos.x++;
		if (dir == UP)
			snake->pos.y--;
		if (dir == DOWN)
			snake->pos.y++;
		if (snake->pos.x == apple->x && snake->pos.y == apple->y) // si il y a une pomme
		{
			snake->score += snake->case_per_sec;
				apple->x = rand_a_b(1, w - 1);
				apple->y = rand_a_b(1, h - 1);
			while (tab[apple->x][apple->y] == ELEM_SNAKE)
			{
				apple->x = rand_a_b(1, w);
				apple->y = rand_a_b(1, h);
			}
			tab[apple->x][apple->y] = ELEM_APPLE;
			snakeadd(snake, x_end, y_end);
		}
		if(tab[snake->pos.x][snake->pos.y] != ELEM_DIESE && tab[snake->pos.x][snake->pos.y] != ELEM_SNAKE)
		{
			snake->dir = dir;
			while (snake)
			{
				tab[snake->pos.x][snake->pos.y] = ELEM_SNAKE;
				snake = snake->next;
			}
			return (1);
		}
	puttab(tab, w, h);
	return(0);
}

int	snake(int **tab, int w, int h, int case_per_sec)
{
	int i;
	int keypress;
	int dir;
	t_snake *snake;
	t_snake *snake2;
	t_point apple;
	snake = (t_snake*)malloc(sizeof(t_snake));
	snake2 = (t_snake*)malloc(sizeof(t_snake));
	snake->mom = NULL;
	snake->pos.x = 5;
	snake->pos.y = 4;
	snake->case_per_sec = case_per_sec;
	snake->score = 0;
	snake->end2 = snake;
	snake->next = NULL;
	snakeadd(snake, 4, 4);
	snakeadd(snake, 3, 4);
	apple.x = 6;
	apple.y = 5;
	tab[apple.x][apple.y] = ELEM_APPLE;
	i = 0;
	dir = RIGHT;
	while(1)
	{
		system("CLEAR");
		keypress = getarrowkey();
		if (keypress != 0)
			dir = keypress;
		if(!updatetab(tab, dir, snake, &apple, w, h))
			return (snake->score);
		puttab(tab, w, h);
		ft_putstr("Score :");
		ft_putnbr(snake->score);
		usleep(1000000 / case_per_sec);
	}
}
int		main(int argc, char **argv)
{
	int w;
	int h;
	int **tab;
	int i;
	int case_per_sec;
	int score;

	i = 0;

	w = ft_atoi(argv[1]);
	h = ft_atoi(argv[2]);
	case_per_sec = ft_atoi(argv[3]);
	tab = (int **)malloc(sizeof(int*) * w);
	while (i < w)
	{
		tab[i] = (int *)malloc(sizeof(int) * h);
		i++;
	}
	set_tab(tab, w, h);
	puttab(tab,w, h);
	score = snake(tab, w, h, case_per_sec);
	ft_putstr("Game over !\nScore final: ");
	ft_putnbr(score);
}
