#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main() {
    int ret_printf, ret_ft_printf;


    ret_printf = printf("%.0d", 0);
    printf("|\n");
    ret_ft_printf = ft_printf("%.0d", 0);
    printf("|\n");
    printf("Returned: printf = %d, ft_printf = %d\n\n", ret_printf, ret_ft_printf);


    return 0;
}
