#ifndef INKY_ERROR_H
    #define INKY_ERROR_H

    /* --- --- --- [ ERROR CLUSTER ] --- --- --- */
        #include "./file.h"
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

    /* --- --- --- [ ERROR LIST ] --- --- --- */
    #define X(type)                                         \
        INKY_##type##_ERROR_BUCKET [] = {                   \
            INKY_TRIVIAL_##type##_ERROR,                    \
            [ INKY_NO_##type##_ERROR ] = (char*)0,          \
            INKY_FATAL_##type##_ERROR                       \
        }

    #define x(error, issue, help)                           \
        [ INKY_##error##_ERROR ] = {                        \
            .i = { issue, sizeof(issue) - 1 },              \
            .h = { help, sizeof(help) - 1 },                \
        }

    const struct INKY_ERROR_BUCKET {
        const struct {
            const char* issue;
            const unsigned int len;
        } i;
        const struct {
            const char* help;
            const unsigned int len;
        } h;
    } INKY_ERROR_TYPE;

    #undef X
    #undef x
    /* --- --- --- */


#endif
