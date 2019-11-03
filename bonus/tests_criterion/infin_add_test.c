/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** test infin_add
*/

#include <criterion/criterion.h>

char    *my_infin_add(char *str, char *str2);

Test(my_infin_add, should_return_zero)
{
    char *result;
    char *a = "0";
    result = my_infin_add(a, a);
    cr_assert_str_eq(result, "0");
}

Test(my_infin_add, should_return_4)
{
    char *result;
    char *a = "1";
    char *b = "3";
    result = my_infin_add(a, b);
    cr_assert_str_eq(result, "4");
}

Test(my_infin_add, should_return_14)
{
    char *result;
    char *a = "8";
    char *b = "6";
    result = my_infin_add(a, b);
    cr_assert_str_eq(result, "14");
}

Test(my_infin_add, should_return_31)
{
    char *result;
    char *a = "13";
    char *b = "18";
    result = my_infin_add(a, b);
    cr_assert_str_eq(result, "31");
}

Test(my_infin_add, should_return_a_big_number)
{
    char *result;
    char *a = "15874125852682";
    char *b = "8584574526874";
    result = my_infin_add(a, b);
    cr_assert_str_eq(result, "24458700379556");
}