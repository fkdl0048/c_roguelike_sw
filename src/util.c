#include <rogue.h> 

long int ft_abs(long int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

int	ft_len(long int nbr)
{
	int		len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*c;

	sign = (n < 0) ? -1 : 1;
	len = ft_len(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' ||
			nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-')
		sign *= -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (n * sign > 2147483647)
			return (-1);
		else if (n * sign < -2147483648)
			return (0);
		else
			n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}