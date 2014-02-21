










#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/includes/libft.h"
#include "minitalk.h"
#include <stdio.h>

//int		g_bin;

static void		ft_printpid(void);
static int		ft_power(int nb, int power);
static void		handler(int sig, siginfo_t *siginfo, void *context);
static void		ft_proceed(char **tmp, int *i, char *c, char **str);
//static void		ft_alloc_msg(char **str, char **tmp);
static void		ft_add_bit(int pid, int bin);

int		main(void)
{
	struct sigaction	 action;

	action.sa_sigaction = handler;
	action.sa_flags |= SA_SIGINFO;
	//	action.sa_flags &= SA_RESETHAND;
	ft_printpid();
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (42)
		{
			pause();
		}
	return (0);
}

/*static void		ft_alloc_msg(char **str, char **tmp)
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
}*/

static void		ft_printpid(void)
{
	pid_t 		pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
}

static void		handler(int sig, siginfo_t *siginfo, void *context)
{
	(void) context;
	//	if (sig == SIGUSR1)
	//	g_bin = 1;
	//else if (sig == SIGUSR2)
	//	g_bin = 0;
	ft_add_bit(siginfo->si_pid, (sig == SIGUSR1));
}

static void		ft_add_bit(int pid, int bin)
{
	static char	*str;
	static char	*tmp;
	static int	i = 0;
	static char	c = 0;

	if (!str)
		{
			str = (char *) malloc(sizeof(char) * 10000);
			tmp = str;
		}
	//	ft_alloc_msg(&str, &tmp);
	c += ft_power(2, i) * bin;
	if (i == 6)
		ft_proceed(&tmp, &i, &c, &str);
	else
		i++;
	kill(pid, SIGUSR2);
}

static void		ft_proceed(char **tmp, int *i, char *c, char **str)
{
	if ((*c) == '\0')
		{
			**tmp = *c;
			ft_putstr(*str);
			ft_strclr(*str);
			//			free(*str);
			//*str = NULL;
			tmp = str;
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
