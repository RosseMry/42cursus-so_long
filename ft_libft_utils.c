#include "so_long.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[h] != '\0')
	{
		n = 0;
		while (haystack[h + n] == needle[n] && (h + n) < len)
		{
			if (haystack[h + n] == '\0' && needle[n] == '\0')
				return ((char *)&haystack[h]);
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)haystack + h);
		h++;
	}
	return (0);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	dest = (char *) malloc (sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	while (src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	i = start;
	if (i >= ft_strlen((char *)s))
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > (ft_strlen((char *)s) - i))
		len = ft_strlen((char *)s) - i;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s[i] && j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

static void	fsplit(char **split, size_t j)
{
	while (j--)
	{
		if (split[j])
		{
			free(split[j]);
			split[j] = NULL;
		}
	}
	free(split);
}

static size_t	segcount(char const *s, char c)
{
	size_t	i;
	size_t	segnum;

	i = 0;
	segnum = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			segnum++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (segnum);
}

static char	**spliter(char **split, char const *s, char c, size_t start)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			split[j] = ft_substr(s, start, i - start);
			if (!split[j])
			{
				fsplit(split, j);
				return (NULL);
			}
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	segnum;
	char	**splited;

	if (!s)
		return (NULL);
	segnum = segcount(s, c);
	splited = (char **)malloc((segnum + 1) * sizeof(char *));
	if (!splited)
		return (NULL);
	if (!spliter(splited, s, c, 0))
		return (NULL);
	return (splited);
}