# include <stdio.h>
# include "source.h"

double fracsum(int x, int y, int a, int b)
{
	double res;

	res = ((double)x / (double)y) + ((double)a / (double)b);
	return (res);
		       	}
