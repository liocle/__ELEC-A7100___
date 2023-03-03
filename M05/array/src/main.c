#include "source.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int	main(void)
{
	int	arr[];
	int	sum;

	arr[] = {10, 100, 1000};
	printf("array_sum with values { 10, 100, 1000 } returned: ");
	sum = array_sum(arr, 3);
	if (sum == 1110)
	{
		printf("%d -- OK!\n", sum);
	}
	else
	{
		printf("%d, but should have been 1110\n", sum);
	}
	return (0);
}
