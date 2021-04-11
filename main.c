#include "get_next_line.h"

int		main()
{
	int		gnl;
	int		fd;
	char	*line[] = {"truc"};
	int		i;
	i = 1;

	fd = open("Nimon77/gnlTester/files/nl", O_RDONLY);


	while ((gnl = get_next_line(fd, line)) == 1)
	{
		i++;
//		printf("|GNL return is %d|\n", gnl);
//		printf("line[0] is |%s|\n", line[0]);
		free(line[0]);
	}
//	printf("|GNL return is %d|\n", gnl);
//	printf("|%s|\n", line[0]);
	free(line[0]);
	close(fd);
	fd = open("Nimon77/gnlTester/files/41_no_nl", O_RDONLY);
	while ((gnl = get_next_line(fd, line)) == 1)
	{
		i++;
//		printf("|GNL return is %d|\n", gnl);
//		printf("line[0] is |%s|\n", line[0]);
		free(line[0]);
	}
//	printf("|GNL return is %d|\n", gnl);
//	printf("|%s|\n", line[0]);
	close(fd);
	return 0;
}
