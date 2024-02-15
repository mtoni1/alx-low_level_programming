#include <stdio.h>
#include <stdlib.h>
#include "main.h"


/**
 * append_text_to_file - function that appends text at the end of a file.
 * @c: where filename is the name of the file and text_content is the NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */


int append_text_to_file(const char *filename, char *text_content) {
    if (filename == NULL) {
        return -1;
    }

    FILE *fp = fopen(filename, "r+"); // Open the file for reading and writing
    if (fp == NULL) {
        return -1;
    }

    if (fseek(fp, 0, SEEK_END) == 0) { // Move the file pointer to the end
        size_t len = strlen(text_content);
        ssize_t bytes_written = fwrite(text_content, sizeof(char), len, fp);
        if (bytes_written == len) {
            fseek(fp, 0, SEEK_END); // Move the file pointer back to the end
            ftruncate(fileno(fp), ftell(fp)); // Truncate the file to its current size
            return 1;
        }
    }

    fclose(fp);
    return -1;
}
