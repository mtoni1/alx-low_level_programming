#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "main.h"


/**
 * read_textfile -  function that reads a text file and prints it to the POSIX standard output
 * @n: number to print, if the file can not be opened or read, return 0(NULL)
 *
 * Return: 1(on success)
 */

int create_file(const char *filename, char *text_content) {
    if (filename == NULL) {
        return -1;
    }

    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1) {
        perror("Error: Can't create file");
        return -1;
    }

    if (text_content != NULL) {
        size_t len = strlen(text_content);
        if (write(fd, text_content, len) != len) {
            perror("Error: Can't write to file");
            close(fd);
            return -1;
        }
    }

    if (close(fd) == -1) {
        perror("Error: Can't close file");
        return -1;
    }

    return 1;
}
