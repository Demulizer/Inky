#ifndef INKY_FILE_ERROR_H
    #define INKY_FILE_ERROR_H

    /* --- --- --- [ FILE ERROR LIST ] --- --- --- */
        /* - - - [ Trivial ] - - - */
            #define INKY_TRIVIAL_FILE_ERROR         \
                x(FILE_EMPTY, "read", "corruption")
        /* - - - */

        /* - - - [ Fatal ] - - - */
            #define INKY_FATAL_FILE_ERROR           \
                x(FILE_PERMISSION, "open, edit, and/or close", "permission")
        /* - - - */

        // SUMMARY:
        // # INKY_*_FILE_ERROR
        //      - lists all expected file related error as FILE_*, with issue and help
        //      - trivial errors do not trigger a program termination
        //      - fatal errors trigger a program termination; can't be ignored
    /* --- --- --- */

#endif
