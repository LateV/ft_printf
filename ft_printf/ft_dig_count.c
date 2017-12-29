
#include "ft_printf.h"

int		ft_dig_count(int a)
{
	int b;
	int d;

	b = 1;
	d = 10;
	while(1)
	{
		if(a / d < 1)
			return (b);
		b++;
		d  = d * 10;
	}
}
