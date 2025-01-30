#include "so_long_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memset(void *str, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)str)[i] = c;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*str;
	size_t			total;
	size_t			totalsize;

	totalsize = (size_t)(-1);
	if (size != 0 && n > totalsize / size)
		return (0);
	total = n * size;
	str = malloc(total);
	if (!str)
		return (0);
	ft_memset(str, '\0', total);
	return (str);
}

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	cc;

	i = ft_strlen((char *)str);
	cc = (unsigned char)c;
	while (i >= 0)
	{
		if (str[i] == cc)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	size;
	size_t	i;
	size_t	j;

	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	dst = malloc(sizeof(char) * size + 1);
	if (!s1 || !s2 || !dst)
		return (0);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i] = s2[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	dst[size] = 0;
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cc;

	cc = (unsigned char)c;
	while (*s != '\0')
	{
		if ((unsigned char)*s == cc)
			return ((char *)s);
		s++;
	}
	if (cc == '\0')
		return ((char *)s);
	return (0);
}
char	*ft_strappend(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;
	char	*str;

	str = (char *)src;
	i = 0;
	lensrc = ft_strlen (str);
	if (size != 0)
	{
		while (str[i] && (i < (size - 1)))
		{
			dst[i] = str[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (lensrc);
}

static size_t	ft_strdest(char *dest, size_t size)
{
	size_t	i;

	i = 0;
	while (dest[i] && i < size)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	size_src;
	size_t	i;

	i = 0;
	size_dest = ft_strdest((char *)dest, size);
	size_src = ft_strlen((char *)src);
	if (size <= size_dest)
		return (size + size_src);
	while (src[i] && (size_dest + i) < (size - 1))
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
	return (size_dest + size_src);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_length;
	char	*substr;

	if (!s)
		return (NULL);
	substr_length = ft_strlen(s) - start;
	if (ft_strlen(s) > start)
	{
		if (substr_length > len)
			substr = (char *) ft_calloc(len + 1, sizeof(char));
		else
			substr = (char *) ft_calloc(substr_length + 1, sizeof(char));
		if (!substr)
			return (NULL);
		ft_strlcpy(substr, &s[start], len + 1);
	}
	else
		substr = (char *) ft_calloc(1, sizeof(char));
	return (substr);
}