

#include <stdlib.h>
#include "puissance4.h"
#include "libft.h"
/*#include "get_next_line.h"*/

void	error_command(char *s)
{
	ft_putstr_fd(s, 2);
	write(2, "\n", 1);
	return ;
}

t_map	*init_map(void)
{
	t_map	*new;

	if ((new = (t_map *)malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->map = NULL;
	new->col = 0;
	new->line = 0;
	return (new);
}

char	**init_tab(int col, int line)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((map = (char **)malloc(sizeof(*map) * (line + 1))) == NULL)
		return (NULL);
	map[line] = '\0';
	while (map[i])
	{
		map[i] = ft_strnew(col);
		i++;
	}
	while (j < line)
	{
		i = 0;
		while (i < col)
		{
			map[j][i] = '.';
			i++;
		}
		j++;
	}
	return (map);
}

t_map	*get_map(char *col, char *line)
{
	t_map	*s_map;

	if ((s_map = init_map()) == NULL)
		return (NULL);
	s_map->col = ft_atoi(col);
	s_map->line = ft_atoi(line);
	s_map->map = init_tab(s_map->col, s_map->line);
	return (s_map);
}

int		check_map(t_map *s_map)
{
	if (s_map->map == NULL)
	{
		error_command("Puissance4: malloc problem");
		return (-1);
	}
	if (s_map->col < 7 || s_map->line < 6)
	{
		error_command("Puissance4: col min = 7, line min = 6");
		return (-1);
	}
	if (s_map->col > 2000 || s_map->line > 2000)
	{
		error_command("Puissance4: map is too big !");
		return (-1);
	}
	return (0);
}

int		check_col1(int col, t_map *s_map)
{
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	while (i < s_map->line)
	{
		if (s_map->map[i][col] == '.')
			flag++;
		i++;
	}
	return (flag);
}

int		is_play_ok(int play, t_map *s_map)
{
	if (play < 0 || play > s_map->col)
		return (1);
	if (!check_col1(play, s_map))
		return (1);
	return (0);
}

void	make_play(int play, t_map *s_map, char chip)
{
	int		i;

	i = 0;
	while (i < s_map->line)
	{
		if (s_map->map[i][play] != '.')
			break ;
		i++;
	}
	s_map->map[i - 1][play] = chip;
}

void	human_turn(t_map *s_map)
{
	char	*buf;
	int		play;
	int		ok;

	ok = -1;
	while (ok)
	{
		get_next_line(0, &buf);
		play = ft_atoi(buf);
		free(buf);
		if ((ok = is_play_ok(play, s_map)) == 1)
			write(1, "play again, incorrect value:\n", 29);
	}
	make_play(play, s_map, 'X');
}

int		print_draw(void)
{
	write(1, "No more chips, play again !\n", 28);
	return (0);
}

int		print_winner(char chip)
{
	if (chip == 'X')
		write(1, "You won ! Thanks for playing !\n", 31);
	else
		write(1, "The computer won ! Shame om you !\n", 34);
	return (0);
}

int		check_line(t_map *s_map, int line, int col, char chip)
{
	int		i;
	int		flag;

	i = col;
	flag = 0;
	while (i < s_map->col && i < col + 4)
	{
		if (s_map->map[line][i] == chip)
			flag++;
		i++;
	}
	if (flag == 4)
		return (1);
	return (0);
}

int		check_col(t_map *s_map, int line, int col, char chip)
{
	int		i;
	int		flag;

	i = line;
	flag = 0;
	while (i < s_map->line && i < line + 4)
	{
		if (s_map->map[i][col] == chip)
			flag++;
		i++;
	}
	if (flag == 4)
		return (1);
	return (0);
}

int		check_diag(t_map *s_map, int line, int col, char chip)
{
	int		i;
	int		j;
	int		flag;

	i = line;
	j = col;
	flag = 0;
	while (i < s_map->line && j < s_map->col && i < (line + 4) && j < (col + 4))
	{
		if (s_map->map[i][j] == chip)
			flag++;
		i++;
		j++;
	}
	if (flag == 4)
		return (1);
	return (0);
}

int		check_four(t_map *s_map, int line, int col, char chip)
{
	if (check_lines(s_map, line, col, chip))
		return (1);
	if (check_col(s_map, line, col, chip))
		return (1);
	if (check_diag(s_map, line, col, chip))
		return (1);
	return (0);
}

int		map_full(t_map *s_map)
{
	int		i;
	int		j;

	i = 0;
	while (i < s_map->line)
	{
		j = 0;
		while (j < s_map->col)
		{
			if (s_map->map[i][j] == '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		is_finish(t_map *s_map, char chip)
{
	int		i;
	int		j;

	i = 0;
	while (i < s_map->line)
	{
		j = 0;
		while (j < s_map->col)
		{
			if (s_map->map[i][j] == chip)
			{
				if (check_four(s_map, i, j, chip))
					return (print_winner(chip));
			}
			j++;
		}
		i++;
	}
	if (map_full(s_map))
		return (print_draw());
	return (1);
}

void	lets_play(int human, int cmp, t_map *s_map)
{
	int		finish;
	char	chip;

	finish = -1;
	chip = '.';
	while (finish)
	{
		print_map(s_map);
		if (human >= cmp)
		{
			human_turn(s_map);
			chip = 'X';
		}
		else
		{
			cmp_turn(s_map); //a faire
			chip = 'O';
		}
		finish = is_finish(s_map, chip);
	}
}

void	start_game(t_map *s_map)
{
	int		player_one;
	int		player_cmp;
	time_t	time;

	srand(time);
	player_one = rand();
	srand(time);
	player_cmp = rand();
	lets_play(player_one, player_cmp, s_map);
}

int		main(int argc, char **argv)
{
	t_map	*s_map;

	if (argc != 3)
	{
		error_command("Usage: ./puissance4 col(int) line(int)");
		return (0);
	}
	else
	{
		s_map = get_map(argv[1], argv[2]);
		if (s_map == NULL || check_map(s_map))
			return (0);
		start_game(s_map);
	}
	return (0);
}
