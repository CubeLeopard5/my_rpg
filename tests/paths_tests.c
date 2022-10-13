/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** paths_tests.c
*/

#include "criterion_tests.h"

Test(get_filename, name_from_fullpath)
{
    char fullpath[] = "/usr/local/bin/this_is_a_test";
    char *filename = get_filename(fullpath);

    cr_assert_str_eq(filename, "this_is_a_test");
}

Test(get_filename, name_from_name)
{
    char fullpath[] = "hello_world.c";
    char *filename = get_filename(fullpath);

    cr_assert_str_eq(filename, "hello_world.c");
    cr_assert_eq(filename, fullpath);
    cr_assert_str_eq(get_filename(""), "");
}

Test(join_path, join_file_to_path)
{
    char base[] = "/usr/local/bin";
    char file[] = "test_program";
    char *fullpath = join_path(base, file);

    cr_assert_str_eq(fullpath, "/usr/local/bin/test_program");
    free(fullpath);
}

Test(join_path, join_file_to_path_with_slashes)
{
    char base[] = "/usr/local/bin/";
    char base2[] = "/usr/local/bin";
    char file[] = "test_program";
    char file2[] = "/test_program";
    char *fullpath = join_path(base, file);
    char *fullpath2 = join_path(base2, file2);

    cr_assert_str_eq(fullpath, "/usr/local/bin/test_program");
    cr_assert_str_eq(fullpath, fullpath2);
    free(fullpath);
    free(fullpath2);
}

Test(join_path, join_path_to_path)
{
    char base[] = "/var/test/";
    char path[] = "/folder/test";
    char *fullpath = join_path(base, path);

    cr_assert_str_eq(fullpath, "/var/test/folder/test");
    free(fullpath);
}
