#include "get_next_line.h"

int		main()
{
	int		gnl;
	int		fd;
	char	**line = NULL;

	fd = open("alph", O_RDONLY);

	while ((gnl = get_next_line(fd, line)))
	{
		printf("GNL return is %d\n", gnl);
		free(*line);
	}
	printf("|%s|\n", *line);
	close(fd);
}
