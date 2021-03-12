#include "get_next_line.h"

int		main()
{
	int		fd;
	char	**line = NULL;

	fd = open("alph", O_RDONLY);

	while ((printf("GNL = %d\n", get_next_line(fd, line)) > 0))
	{
		printf("|%s|\n", *line);

	}
	close(fd);
}
