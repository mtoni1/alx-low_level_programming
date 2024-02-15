#include <stdio.h>
#include <stdlib.h>
#include "main.h"


/**
 * read_textfile -  function that reads a text file and prints it to the POSIX standard output
 * @n: number to print, if the file can not be opened or read, return 0(NULL)
 *
 * Return: 1(on success)
 */


ssize_t read_textfile(const char *filename, size_t letters) {
    if (filename == NULL) {
        return 0;
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    char *buffer = (char *) malloc(letters + 1);
    if (buffer == NULL) {
        fclose(fp);
        return 0;
    }

    ssize_t bytes_read = fread(buffer, sizeof(char), letters, fp);
    if (bytes_read == -1) {
        fclose(fp);
        free(buffer);
        return 0;
    }

    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    free(buffer);
    fclose(fp);

    return bytes_read;
}
