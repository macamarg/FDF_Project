

#include "fdf.h"


int	find_color(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			return (1);
		i++;
	}
	return (0);
}

int	g_color(char *str)
{
	char	*temp;
	int		result;

	result = 0;
	temp = str;
	while (*temp)
	{
		if (*temp == 'x')
		{
			result = ft_atoi_base (++temp, 16);
		}
		temp++;
	}
	return (result);
}
