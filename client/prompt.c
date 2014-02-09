





#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "../libft/includes/get_next_line.h"
#include "../libft/includes/libft.h"

static void				ft_chartobin(char c, char *tab);

static void				send(char c, int pid);

void				prompt(int pid, char *line)
{
	int		i;

	i = 0;
	while (line[i])
		{
			send(line[i], pid);
			i++;
		}
	send('\n', pid);
	send('\0', pid);
}

void	ft_send_len(int pid, size_t len)
{
	int	i;

	i = 32;
	while (i)
		{
			if (len % 2)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			len /= 2;
			pause();
			i--;
		}
}

static void			send(char c, int pid)
{
	char		*tab;
	int			i;

	tab = (char *)malloc(7 * sizeof(char));
	ft_chartobin(c, tab);
	i = 6;
	while (i >= 0)
		{
			if (tab[i] == 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			pause();
			i--;
		}
	free(tab);
}

static void				ft_chartobin(char c, char *tab)
{
	int					i;

	i = 7;
	while (i > 0)
		{
			i--;
			tab[i] = c % 2;
			c /= 2;
		}
}
