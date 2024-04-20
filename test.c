#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;
	unsigned char	*ss1;
	unsigned char	*ss2;

	count = 0;
	if (n == 0)
		return (0);
	ss1 = (unsigned char *) s1;
	ss2 = (unsigned char *) s2;
	while (count < n && (ss1[count] || ss2[count]))
	{
		if (ss1[count] != ss2[count])
			return (ss1[count] - ss2[count]);
		count++;
	}
	return (0);
}

int main()
{
    printf("%d\n", ft_strncmp("rr", "rr", 4));
    return (0);
}