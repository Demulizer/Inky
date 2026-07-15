#ifndef INKY_ERROR_H
    #define INKY_ERROR_H

    /* --- --- --- [ ERROR CLUSTER ] --- --- --- */
        #include "./file.h"
#include <errno.h>
#include <stddef.h>
    /* --- --- --- */

    /* --- --- --- [ ERROR TYPES ] --- --- --- */
        #define INKY_ERROR_TYPE                             \
            X(FILE)

        /* - - - [ IDs ] - - - */
            #define X(type)                                 \
                INKY_##type##_ERROR_NUMBER {                \
                    INKY_TRIVIAL_##type##_ERROR,            \
                    INKY_NO_##type##_ERROR,                 \
                    INKY_FATAL_##type##_ERROR,              \
                    INKY_##type##_ERROR_COUNT               \
                }

            #define x(error, issue, help)                   \
                INKY_##error##_ERROR

            enum INKY_ERROR_TYPE;

            #undef X
            #undef x
        /* - - - */

        // SUMMARY:
        //
        // # INKY_ERROR_TYPE
        //      - is a list of error related types to be expected
        //
        // # INKY_ERROR_NUMBER
        //      - is an enum of error index for each error type with a count
        //      - relies on the expansion of INKY_ERROR_TYPE to INKY_*_ERROR via X macro
        //
        // # INKY_*_ERROR_NUMBER
        //      - is an enum of a list of error codes (counted) expanded from INKY_ERROR_TYPE
        //      - INKY_NO_*_ERROR centered, divides trivial (<) and fatal (>) error codes
        //      - heavily relies on the naming convention for error code generation
        //      - expects all x(error, help) "error" to be unique for naming
    /* --- --- --- */

    /* --- --- --- [ ERROR LISTING AND LOOKUP ] --- --- --- */
        /* - - - [ Listing ] - - - */
            #define X(type)                                         \
                INKY_##type##_ERROR_BUCKET [] = {                   \
                    INKY_TRIVIAL_##type##_ERROR,                    \
                    [ INKY_NO_##type##_ERROR ] = (char*)0,          \
                    INKY_FATAL_##type##_ERROR                       \
                }

            #define INKY_ERROR_FORMAT(error, issue, help)           \
                #error"\n"                                          \
                "  -" issue " issue\n"                              \
                "  -check " help "\n"

            #define x(error, issue, help)                           \
                [ INKY_##error##_ERROR ] = {                        \
                    .Error = {                                      \
                        .message = INKY_ERROR_FORMAT(               \
                            INKY_##error##_ERROR, issue, help       \
                        ),                                          \
                        .length = sizeof(INKY_ERROR_FORMAT(         \
                            INKY_##error##_ERROR, issue, help       \
                        )) - 1                                      \
                    },                                              \
                    .Code = INKY_##error##_ERROR                    \
                }

            const struct INKY_ERROR_BUCKET {
                const struct {
                    const char* message;
                    const int length;
                } Error;
                const int Code;
            } INKY_ERROR_TYPE;

            #undef X
            #undef INKY_ERROR_FORMAT
            #undef x
        /* - - - */

        // SUMMARY:
        //
        // # INKY_ERROR_BUCKET
        //      - is a compile-time lookup table for each error type
        //      - indexed directly by the corresponding INKY_*_ERROR enum value
        //      - stores immutable error metadata and the associated error code
        //
        // # INKY_ERROR_FORMAT(error, issue, help)
        //      - builds a compile-time formatted error message string
        //      - stringifies the error identifier and embeds issue/help text
        //
        // # x(error, issue, help)
        //      - converts an error definition into an indexed bucket entry
        //      - computes the formatted message length at compile time
        //      - relies on the x(error, issue, help) entries defined by each error type
    /* --- --- --- */


#endif
