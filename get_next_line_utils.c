/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ichougra <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 18:07:49 by ichougra     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 20:24:23 by ichougra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_l(char const *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!(res = malloc(sizeof(char) * (ft_l(s1) + ft_l(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_sub(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	c;
	size_t	n;

	p = malloc(len + 1 * sizeof(char));
	if (p == NULL)
		return (NULL);
	c = 0;
	n = 0;
	while (s[n])
		n++;
	if (start > n)
		len = 0;
	while (c < len && s[start + c] != '\0')
	{
		p[c] = s[start + c];
		c++;
	}
	p[c] = '\0';
	return (p);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = ft_l(s1);
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
