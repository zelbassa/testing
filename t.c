#include <stdio.h>

int		find_min(int *stack, int len)
{
	int	i;
	int	k;
	int	min_value;

	i = 0;
	k = 1;
	min_value = 0;
	while (i < len - 1 && k + i < len)
	{
		if (stack[i] < stack[i + k])
			k ++;
		else
		{
			i = k;
			k ++;
		}
		min_value = i;
	}
	return (min_value);
}

int main()
{
	return(0);
}