#include <stdio.h>
# include <limits.h>
#include "includes/ft_printf.h"
#include <locale.h>

int main()
{
	// long long ll;
	// long l;
	// intmax_t j;
	// int 	z;

	// ll = 1844674407370955161;
	// l = 123456;
	// j = 123456;
	// z = 123456;
	// ft_printf("long long = %10.3lld\n", ll);
	// printf("long long = %10.3lld\n", ll);
	// ft_printf("long = %10.3ld\n", l);
	// printf("long = %10.3ld\n", l);
	// ft_printf("intmax_t = %10.3jd\n", j);
	// printf("intmax_t = %10.3jd\n", j);	

// int	p;

// p = 5;
//     ft_printf("%jx\n", -4294967296);
//    ft_printf("%#o\n", 0);
// wchar_t newstring[7] = {0x43, 0x01A9, 0x43, 0x01A9, 0x01A9, 0x01A9, 0};
wchar_t newstring[7] = {0x01A9, 0x01A9, 0x01A9, 0x01A9, 0x01A9, 0x01A9, 0};

//	ft_putwchar(33121);

	setlocale(LC_ALL, "");

	printf("ft = %d\n", ft_printf("%ls\n", newstring));
	printf("reg = %d\n", printf("%S\n", newstring));
//    printf("reg = %d %C %s %d %u %X %c", 123, L'ÊM-^ZM-^V', "123", 123, -1, 123, 'a');
    	// printf("%#8x\n", 2);
    // printf("%#o\n", 0);
    // printf("%#o\n", 0);
	// while(1);
//	printf("1234 %-03c 9 \n", 'a');
}

