/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:23:22 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/11 12:40:46 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ELEM_DIESE 1
#define ELEM_VOID 2
#define ELEM_SNAKE 3
#define ELEM_APPLE 4
#define UP 2
#define LEFT 1
#define RIGHT 4
#define DOWN 3


typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_snake
{
	t_point pos;
	int dir;
	
	struct s_snake *end2;
	struct s_snake *next;
	struct s_snake *mom;
	int score;
	int case_per_sec;
}				t_snake;

int		getarrowkey(void);
int		rand_a_b(int a, int b);
