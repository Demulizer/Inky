#include <stdio.h>
#include <unistd.h>

#include "./include/error/error.h"

int main(void)
{
    fwrite(
        INKY_FILE_ERROR_BUCKET[INKY_FILE_EMPTY_ERROR].Error.message,
        INKY_FILE_ERROR_BUCKET[INKY_FILE_EMPTY_ERROR].Error.length,
        1, stderr
    );
    fprintf(stderr, "[ %d ]\n", INKY_FILE_EMPTY_ERROR);


    return 0;
}
