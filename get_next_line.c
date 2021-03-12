#include "get_next_line.h"

void	ft_putchar(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		write(1, &s[i], 1);
	return ;
}

/*

   int		get_next_line(int fd, char **line)
   {
   int		i;
   char	*read_str;
   static char *scrap;

   i = 0;
   scrap = NULL;

   if (!(read_str = malloc(BUFFER_SIZE)))
   return (-1);
   read(fd, read_str, BUFFER_SIZE);
   while (read_str[i] != 0)
   {
   if (read_str[i] == '\n')
   {
   scrap = &read_str[i];
   return (1);
   }
   ft_putchar(read_str);
   }

   if (line == 0)
   return (0);
   }*/

#define BUFFER_SIZE 12
int             ft_strlen(const char *s)
{
        int     i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

char    *ft_strdup(const char *src)
{
        int             size;
        char    *str;
        int             i;

        size = ft_strlen(src);
        if (!(str = malloc(sizeof(char) * size + 1)))
                return (0);
        i = 0;
        while (src[i])
        {
                str[i] = src[i];
                i++;
        }
        str[i] = '\0';
        return (str);
}

int		line_size(char *string)
{
	int	i;
	i = 0;
	while (string[i] != '\n' && i < BUFFER_SIZE && string[i] != 0)
		i++;
	return (i);
}

int		fill_the_line(char **tab, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (str[i] != '\n' && str[i])
	{
		tab[j][i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		tab[j][i] = 0;
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int				i;
	int				endofline;
	char			buf[BUFFER_SIZE + 1];
	int				size;

	i = 0;
	size = 0;
	while (n_read == 0)
	{
																				if (i != 0) {printf("endofline = %d\n", endofline);}
		if ((size = read(fd, buf, BUFFER_SIZE) < 0))
			return (-1);
																				printf("size = %d\n", size);
		i++;
		n_read = fill_the_line(line, buf)
																				printf("i = %d\n", i);
																				printf("buf = %s\n", buf);
																				printf("fd = %d\n", fd);
	}
	if (size < BUFFER_SIZE)
		return (0);

	if (endofline == 0)
		return (1);
	else
		return (-1);
}
