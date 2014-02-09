










#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/includes/libft.h"
#include "minitalk.h"

int		g_bin;

static void		ft_printpid(void);
static int		ft_power(int nb, int power);
static void		ft_handle_usr2(void);
static void		ft_handle_usr1(void);
static void		handler(int sig);
static void		ft_proceed(char **str, int *i, char *c);

int		main(void)
{
	char		*str;
	int			i;
	char		c;

	c = 0;
	i = 0;
	str = (char *) malloc(sizeof(char));
	ft_printpid();
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (42)
		{
			pause();
			c += ft_power(2, i) * g_bin;
			if (i == 6)
				ft_proceed(&str, &i, &c);
			else
				i++;
		}
	free(str);
	return (0);
}

static void		ft_printpid(void)
{
	pid_t 		pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
}

static void		handler(int sig)
{
	if (sig == SIGUSR1)
		g_bin = 1;
	else if (sig == SIGUSR2)
		g_bin = 0;
}

static void		ft_proceed(char **str, int *i, char *c)
{
		char		tab[2];

	tab[1] = '\0';
	tab[0] = *c;
	if ((*c) == '\0')
		{
			ft_putstr(*str);
			ft_strclr(*str);
			*str = ft_strfjoin(*str, tab);
		}
	else
		*str = ft_strfjoin(*str, tab);
	*i = 0;
	*c = 0;
}

static int		ft_power(int nb, int power)
{
	int	new;

	new = 1;
	while (power)
		{
			new *= nb;
			power--;
		}
	return (new);
}
