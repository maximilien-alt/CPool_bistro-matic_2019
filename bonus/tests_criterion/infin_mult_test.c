/*
** EPITECH PROJECT, 2019
** bistro matic
** File description:
** tests for infin mult
*/

#include <criterion/criterion.h>

char *my_infin_mult(char *str, char *str2);

Test(my_infin_mult, should_return_zero)
{
    char *result;
    char *a = "14785485455445";
    char *b = "0";
    result = my_infin_mult(a, b);
    cr_assert_str_eq(result, "0");
}

Test(my_infin_mult, should_return_16)
{
    char *result;
    char *a = "8";
    char *b = "2";
    result = my_infin_mult(a, b);
    cr_assert_str_eq(result, "16");
}

Test(my_infin_add, should_return_minus_16)
{
    char *result;
    char *a = "8";
    char *b = "-2";
    result = my_infin_mult(a, b);
    cr_assert_str_eq(result, "-16");
}

Test(my_infin_add, should_return_16)
{
    char *result;
    char *a = "-8";
    char *b = "-2";
    result = my_infin_mult(a, b);
    cr_assert_str_eq(result, "16");
}

Test(my_infin_add, should_return_a_big_number)
{
    char *result;
    char *a = "11111111111111111111";
    char *b = "-2";
    result = my_infin_mult(a, b);
    cr_assert_str_eq(result, "-22222222222222222222");
}