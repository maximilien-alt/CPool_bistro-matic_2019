/*
** EPITECH PROJECT, 2019
** bistro matic
** File description:
** test infinsub
*/


#include <criterion/criterion.h>

char *my_infin_sub(char *str, char *str2);

Test(my_infin_sub, should_return_zero)
{
    char *result;
    char *a = "2";
    result = my_infin_sub(a, a);
    cr_assert_str_eq(result, "0");
}

Test(my_infin_sub, should_return_4)
{
    char *result;
    char *a = "6";
    char *b = "2";
    result = my_infin_sub(a, b);
    cr_assert_str_eq(result, "4");
}

Test(my_infin_sub, should_return_minus_1)
{
    char *result;
    char *a = "9";
    char *b = "10";
    result = my_infin_sub(a, b);
    cr_assert_str_eq(result, "-1");
}

Test(my_infin_sub, should_return_minus_25)
{
    char *result;
    char *a = "13";
    char *b = "38";
    result = my_infin_sub(a, b);
    cr_assert_str_eq(result, "-25");
}

Test(my_infin_sub, should_return_a_big_number)
{
    char *result;
    char *a = "1587412585268232";
    char *b = "-8467953567898765432345678987654323456789";
    result = my_infin_sub(a, b);
    cr_assert_str_eq(result, "-8467953567898765432345677400241738188557");
}