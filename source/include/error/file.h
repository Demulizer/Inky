#ifndef ERROR_FILE_H
    #define ERROR_FILE_H
#include <stdio.h>
#endif


/* --- --- --- [ ERROR TYPES ] --- --- --- */
    /* - - - [ FATAL ] - - - */
        #define FILE_ERROR_TYPE_FATAL           \
            X(READ)
    /* - - - */

    /* - - - [ WARNING ] - - - */
        #define FILE_ERROR_TYPE_WARNING         \
            X(EMPTY)
    /* - - - */
/* --- --- --- */

/* --- --- --- [ ERROR NUMBERS ] --- --- --- */
    #define X(x) FILE_##x##_ERROR_NUMBER
    enum FileErrorNumber {
        /* FATAL */
        FILE_ERROR_TYPE_FATAL,

        /* CHECKPOINT */
        // > ERRORs
        FILE_ERROR_NONE,
        // <= WARNINGs

        /* WARNINGS */
        FILE_ERROR_TYPE_WARNING,

        /* ERROR COUNT */
        FILE_ERROR_COUNT
    };
    #undef X
/* --- --- --- */

/* --- --- --- [ ERROR TABLE ] --- --- --- */
    /* - - - [ UTILITY ] - - - */
    #define FILE_ERROR(x) FILE_##x##_ERROR_NUMBER
    /* - - - */

    /* - - - [ FATAL ] - - - */
        #define X(x) \
            [ FILE_ERROR(x) ] = "FATAL: FILE_"#x"_ERROR"
        const char* const FileErrorLookupFatal[] = {
            FILE_ERROR_TYPE_FATAL
        };
        #undef X
    /* - - - */

    /* - - - [ WARNING ] - - - */
        #define X(x) \
            [ ( FILE_ERROR(x) ) - FILE_ERROR_NONE - 1]     \
            = "WARNING: FILE_"#x"_ERROR"
        const char* const FileErrorLookupWarning[] = {
            FILE_ERROR_TYPE_WARNING
        };
        #undef X
    /* - - - */

    /* - - - [ ERROR LOOKUP ] - - - */
    #define FILE_ERROR_MESSAGE(index)                               \
        write(STDOUT_FILENO,                                        \
        (index < FILE_ERROR_NONE)                                   \
            ? FileErrorLookupFatal[index]                           \
            : FileErrorLookupWarning[index - FILE_ERROR_NONE - 1]   \
        , strlen((index < FILE_ERROR_NONE)                          \
            ? FileErrorLookupFatal[index]                           \
            : FileErrorLookupWarning[index - FILE_ERROR_NONE - 1]   \
        ))
    /* - - - */
/* --- --- --- */
