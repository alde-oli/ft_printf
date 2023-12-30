/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:05:09 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/30 20:33:37 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main() {
    char *str = NULL;
    int ret_printf, ret_ft_printf;

    // Test sans flags
    ret_printf = printf("Standard printf (sans flags): %s\n", str);
    ret_ft_printf = ft_printf("Custom ft_printf(sans flags): %s\n", str);
    printf("Returned: printf = %d, ft_printf = %d\n\n", ret_printf, ret_ft_printf);

    // Test avec largeur de champ
    ret_printf = printf("Standard printf (avec largeur): |%20s|\n", str);
    ret_ft_printf = ft_printf("Custom ft_printf(avec largeur): |%20s|\n", str);
    printf("Returned: printf = %d, ft_printf = %d\n\n", ret_printf, ret_ft_printf);

    // Test avec alignement à gauche
    ret_printf = printf("Standard printf (alignement à gauche): |%-20s|\n", str);
    ret_ft_printf = ft_printf("Custom ft_printf(alignement à gauche): |%-20s|\n", str);
    printf("Returned: printf = %d, ft_printf = %d\n\n", ret_printf, ret_ft_printf);

    // Test avec précision
    ret_printf = printf("Standard printf (avec précision): |%.5s|\n", str);
    ret_ft_printf = ft_printf("Custom ft_printf(avec précision): |%.5s|\n", str);
    printf("Returned: printf = %d, ft_printf = %d\n\n", ret_printf, ret_ft_printf);

    // Test avec largeur de champ et précision
    ret_printf = printf("Standard printf (largeur et précision): |%10.5s|\n", str);
    ret_ft_printf = ft_printf("Custom ft_printf(largeur et précision): |%10.5s|\n", str);
    printf("Returned: printf = %d, ft_printf = %d\n", ret_printf, ret_ft_printf);

    return 0;
}

