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

int		nbn(char *str, int pos_end_line)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			nb++;
		if (nb == 1)
			pos_end_line = i;
		i++;
	}
	return (nb);
}

int		fill_charline(char **tab, char *str, int n_read, int pos_end_line)
{
	int		i;

	if (n_read == 0)
		i = pos_end_line;

}

int		get_next_line(int fd, char **line)
{
	static int		pos_end_line;
	int				n_read;
	char			buf[BUFFER_SIZE + 1];
	int				size;

	pos_end_line = 0;
	size = 0;
	n_read = 0;
	while (n_read == 0)
	{
		if ((size = read(fd, buf, BUFFER_SIZE) < 0))
			return (-1);
		n_read = nbn(buf, pos_end_line);
		fill_charline(line, buf, n_read, pos_end_line);
	}
	if (size < BUFFER_SIZE)
		return (0);

	if (n_read != 0)
		return (1);
	else
		return (-1);
}
