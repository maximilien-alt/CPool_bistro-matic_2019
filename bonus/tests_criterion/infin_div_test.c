/*
** EPITECH PROJECT, 2019
** bistro matic
** File description:
** tests for division
*/


#include <criterion/criterion.h>

char *my_infin_div(char *str, char *div)

Test(my_infin_add, should_return_error)
{
    char *result;
    char *a = "4128751524248525852525";
    char *b = "0";
    result = my_infin_div(a, b);
    cr_assert_str_eq(result, "error");
}

Test(my_infin_add, should_return_5)
{
    char *result;
    char *a = "15";
    char *b = "3";
    result = my_infin_div(a, b);
    cr_assert_str_eq(result, "5");
}

Test(my_infin_add, should_return_minus_15)
{
    char *result;
    char *a = "-45";
    char *b = "3";
    result = my_infin_div(a, b);
    cr_assert_str_eq(result, "-15");
}

Test(my_infin_add, should_return_15)
{
    char *result;
    char *a = "-45";
    char *b = "-3";
    result = my_infin_div(a, b);
    cr_assert_str_eq(result, "15");
}

Test(my_infin_add, should_return_error)
{
    char *result;
    char *a = "8767890767867896786786";
    char *b = "89878978978970097978";
    result = my_infin_div(a, b);
    cr_assert_str_eq(result, "97");
}