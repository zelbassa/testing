#include "push_swap.h"

static int	ft_abs(int n1)
{
	if (n1 < 0)
		return (-n1);
	return (n1);
}

static int	findClosest(int arr[], int n, int target)
{
	int	closestNum;
	int	i;

	i = 0;
	closestNum = arr[0];
	while (i < n)
	{
		if (ft_abs(target - closestNum) > ft_abs(target - arr[i]))
			closestNum = arr[i];
		i++;
	}
	return (closestNum);
}

int	mid_number(int	**arr, int len)
{
	int	i;
	int	total;
	int	target;

	i = 0;
	total = 0;
	while (i < len)
	{
		total += (*arr)[i];
		i++;
	}
	target = total / len;
	return (findClosest(*arr, len, target));
}
