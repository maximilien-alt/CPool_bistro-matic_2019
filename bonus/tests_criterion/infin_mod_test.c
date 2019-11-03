/*
** EPITECH PROJECT, 2019
** bistro matic
** File description:
** test for modulo
*/

#include <criterion/criterion.h>

char    *my_infin_mod(char *str, char *div);

Test(my_infin_mod, should_return_error)
{
    char *result;
    char *a = "14785485455445";
    char *b = "0";
    result = my_infin_mod(a, b);
    cr_assert_str_eq(result, "error");
}

Test(my_infin_mod, should_return_1)
{
    char *result;
    char *a = "5";
    char *b = "2";
    result = my_infin_mod(a, b);
    cr_assert_str_eq(result, "1");
}

Test(my_infin_mod, should_return_9)
{
    char *result;
    char *a = "9";
    char *b = "125";
    result = my_infin_mod(a, b);
    cr_assert_str_eq(result, "9");
}

Test(my_infin_mod, should_return_a_big_number)
{
    char *result;
    char *a = "398209582093850983098230980592380958230958";
    char *b = "3059309509";
    result = my_infin_mod(a, b);
    cr_assert_str_eq(result, "2487433422");
}

Test(my_infin_mod, should_return_a_big_negative_number)
{
    char *result;
    char *a = "-398209582093850983098230980592380958230958";
    char *b = "3059309509";
    result = my_infin_mod(a, b);
    cr_assert_str_eq(result, "-2487433422");
}