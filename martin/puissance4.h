
#ifndef PUISSANCE4_H
# define PUISSANCE4_H

typedef struct	s_map
{
	char	**map;
	int		col;
	int		line;
}				t_map;

void	lets_play(int human, int cmp, t_map *s_map);
int		print_draw(void);

#endif /* !PUISSANCE4_h */
