#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "include/error/file.h"

int main(void)
{
    FILE_ERROR_MESSAGE(FILE_ERROR(EMPTY));
    putchar(10);

    return 0;
}
