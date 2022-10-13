/*
** EPITECH PROJECT, 2020
** init inputs
** File description:
** init the inputs
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "function.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"

void init_input(inputs_t *inputs)
{
    inputs->down = sfKeyS;
    inputs->up = sfKeyZ;
    inputs->right = sfKeyD;
    inputs->left = sfKeyQ;
}