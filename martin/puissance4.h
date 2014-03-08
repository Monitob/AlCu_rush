/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 21:08:36 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/08 22:47:32 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# define EMPTY '.'
# define P_ONE 'X'
# define P_TWO 'O'

typedef struct	s_map
{
	char	**map;
	int		col;
	int		line;
}				t_map;


void	error_command(char *s);
t_map	*get_map(char *col, char *line);
int		is_play_ok(int play, t_map *s_map);
void	make_play(int play, t_map *s_map, char chip);
int		check_four(t_map *s_map, int line, int col, char chip);
void	human_turn(t_map *s_map, char chip);
void	print_map(t_map *s_map);
int		print_winner(char chip);
int		print_draw(void);
int		is_finish(t_map *s_map, char chip);
int		verify_letter(char *s);
int		can_i_stop(t_map *s_map);
int		can_i_play(t_map *s_map, int line, int col);
int		play_something(t_map *s_map);
int		is_play_col(t_map *s_map, int line, int col, int add);
int		can_i_win(t_map *s_map);
int		find_chip(t_map *s_map, int nb);

#endif /* !PUISSANCE4_h */
