










#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/includes/libft.h"
#include "minitalk.h"

t_dat	g_dat;

static void		ft_printpid(void);
static int		ft_power(int nb, int power);
static void		ft_handle_usr2(void);
static void		ft_handle_usr1(void);
static void		handler(int sig);
static void		ft_proceed(void);

int		main(void)
{
	g_dat.c[0] = 0;
	g_dat.c[1] = 0;
	g_dat.i = 0;
	g_dat.str = NULL;
	ft_printpid();
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (42)
		;
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
		ft_handle_usr1();
	else if (sig == SIGUSR2)
		ft_handle_usr2();
	if (g_dat.i == 7)
		ft_proceed();
}

static void		ft_proceed(void)
{
	if (g_dat.c[0] == '\0' && g_dat.str)
		{
			ft_putstr(g_dat.str);
			free(g_dat.str);
			g_dat.str = NULL;
		}
	else
		ft_strfjoin(g_dat.str, g_dat.c);
	g_dat.c[0] = 0;
	g_dat.i = 0;
}

static void		ft_handle_usr2(void)
{
	g_dat.c[0] += ft_power(2, g_dat.i);
	g_dat.i++;
}

static void		ft_handle_usr1(void)
{
	g_dat.i++;
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
