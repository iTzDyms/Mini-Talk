










#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/includes/libft.h"
#include "minitalk.h"

int		g_bin;

static void		ft_printpid(void);
static int		ft_power(int nb, int power);
static void		handler(int sig);
static void		ft_proceed(char **tmp, int *i, char *c, char **str);
static void		ft_alloc_msg(char **str, char **tmp);

int		main(void)
{
	char		*str;
	int			i;
	char		c;
	char		*tmp;

	c = 0;
	i = 0;
	str = NULL;
	ft_printpid();
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (42)
		{
			pause();
			if (!str)
				ft_alloc_msg(&str, &tmp);
			c += ft_power(2, i) * g_bin;
			if (i == 6)
				ft_proceed(&tmp, &i, &c, &str);
			else
				i++;
		}
	free(str);
	return (0);
}

static void		ft_alloc_msg(char **str, char **tmp)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < 32)
		{
			len += ft_power(2, i) * g_bin;
			i++;
			pause();
		}
	*str = (char *) malloc(sizeof(char) * len + 2);
	*tmp = *str;
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

static void		ft_proceed(char **tmp, int *i, char *c, char **str)
{
	ft_putchar(*c);
	if ((*c) == '\0')
		{
			**tmp = *c;
			ft_putstr(*str);
			ft_strclr(*str);
			free(*str);
			*str = NULL;
		}
	else
		**tmp = *c;
	*i = 0;
	*c = 0;
	*tmp += 1;
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
