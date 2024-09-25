/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:02:06 by macamarg          #+#    #+#             */
/*   Updated: 2024/09/16 10:55:47 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

static int	words_count(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (count);
		}
		else
		{
			while (s[i] == c)
				i++;
		}
	}
	return (count);
}

static void	free_array(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

static void	splited_array(char **splited, char const *s, char c)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		size = 0;
		while (s[j] == c && s[j] != '\0')
			j++;
		while (s[j] != c && s[j] != '\0')
		{
			j++;
			size++;
		}
		if (size != 0)
		{
			splited[i] = (char *)malloc(sizeof(char) * (size + 1));
			if (!splited[i])
				return (free_array (splited, i));
			i++;
		}
	}
}

static void	split(char **splited, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[k] != '\0')
	{
		j = 0;
		while (s[k] == c && s[k] != '\0')
			k++;
		if (s[k] != '\0')
		{
			while (s[k] != c && s[k] != '\0')
			{
				splited[i][j] = s[k];
				j++;
				k++;
			}
			splited[i][j] = '\0';
			i++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int			words_num;
	char		**splited;

	if (s == NULL)
		return (NULL);
	words_num = words_count(s, c);
	splited = (char **)malloc(sizeof(char *) * (words_num + 1));
	if (!splited)
	{
		free(splited);
		return (NULL);
	}
	else if (words_num == 0)
	{
		splited[0] = NULL;
		return (splited);
	}
	splited_array(splited, s, c);
	split(splited, s, c);
	splited[words_num] = NULL;
	return (splited);
}

/* void print_splited(char **splited) {
    if (splited == NULL) {
        printf("Splited array is NULL.\n");
        return;
    }

    int i = 0;
    while (splited[i] != NULL) {
        printf("Part %d: %s\n", i, splited[i]);
        i++;
    }
} */

/* // Test function to free the array
void free_splited(char **splited) {
    if (splited == NULL) {
        return;
    }

    int i = 0;
    while (splited[i] != NULL) {
        free(splited[i]);
        i++;
    }
    free(splited);  // Don't forget to free the main array
} */

/* int main() {
    // Test cases for the ft_split function
    char *s1 = "   lorem   ipsum dolor sit amet   ";
    char *s2 = "no delimiters here   ";
    char *s3 = "////leading////slashes////";
    char *s4 = "trailing////slashes////";
    char *s5 = "////////";
    char c = '/';

    // Test with normal input
    char **split1 = ft_split(s1, ' ');
    printf("Test case 1:\n");
    print_splited(split1);

    // Test with no delimiters
    char **split2 = ft_split(s2, ' ');
    printf("Test case 2:\n");
    print_splited(split2);

    // Test with leading delimiters
    char **split3 = ft_split(s3, c);
    printf("Test case 3:\n");
    print_splited(split3);

    // Test with trailing delimiters
    char **split4 = ft_split(s4, c);
    printf("Test case 4:\n");
    print_splited(split4);

  
    char **split5 = ft_split(s5, c);
    printf("Test case 5:\n");
    print_splited(split5);


    free_splited(split1);
    free_splited(split2);
    free_splited(split3);
    free_splited(split4);
    free_splited(split5);

    return 0;
} */