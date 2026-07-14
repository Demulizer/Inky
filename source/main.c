#include <stdio.h>

#include "./include/error/error.h"

int main(void)
{
    printf("%s\n", INKY_FILE_ERROR_BUCKET[INKY_FILE_EMPTY_ERROR].i);
    printf("%s\n", INKY_FILE_ERROR_BUCKET[INKY_FILE_EMPTY_ERROR].h);

    printf("%s\n", INKY_FILE_ERROR_BUCKET[INKY_FILE_PERMISSION_ERROR].i);
    printf("%s\n", INKY_FILE_ERROR_BUCKET[INKY_FILE_PERMISSION_ERROR].h);

    return 0;
}
