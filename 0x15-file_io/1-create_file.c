#include <stdio.h>
#include <stdlib.h>
#include "main.h"


/**
 * create_file -  function that creates a file
 * @c: where filename is the name of the file to create and text_content is a NULL terminated string to write to the file
 * 
 * Returns: 1 on success, -1 on failure
 */



int create_file(const char *filename, char *text_content) {
    if (filename == NULL) {
        return -1;
    }

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return -1;
    }

    if (text_content != NULL) {
        size_t len = strlen(text_content);
        ssize_t bytes_written = fwrite(text_content, sizeof(char), len, fp);
        if (bytes_written == -1) {
            fclose(fp);
            return -1;
        }
    }

    fclose(fp);

    struct stat st;
    if (stat(filename, &st) == 0) {
        chmod(filename, S_IRUSR | S_IWUSR);
    }

    return 1;
}
