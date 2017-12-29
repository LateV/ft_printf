
#include "ft_printf.h"

int main(void)
{
	int kek;
	int kek1;
	//printf("%.10f\n",kek );


	/* komplex */

	kek = ft_printf("str = %010.5s\nchar = %10c\n", "lolkek" , 'L');
	printf("-----------------------------------------------------\n");
	kek1 = printf("str = %010.5s\nchar = %10c\n", "lolkek" , 'L');

	/*         */


	/* %s */

	//kek = ft_printf("str = %10.5s\n", "lolkek");
	//printf("-----------------------------------------------------\n");
	//kek1 = printf("str = %10.5s\n", "lolkek");

	/*     */



	/* %c */

	//kek = ft_printf("char = %10c\n",'k');
	//printf("-----------------------------------------------------\n");
	//kek1 = printf("char = %10c\n",'k');

	/*    */


	printf("return ft_printf : %d\n", kek);
	printf("return printf : %d\n", kek1);
}
