#include "main.h"

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

/**
 * @brief Creates a file with the given filename and writes the given text content to it.
 *
 * @param filename The name of the file to create.
 * @param text_content A NULL terminated string to write to the file.
 *
 * @return 1 on success, -1 on failure (file can not be created, file can not be written, write "fails", etc.).
 *
 * @note The created file must have permissions rw-------. If the file already exists, its contents are truncated.
 *
 * @note If filename is NULL, the function returns -1.
 *
 * @note If text_content is NULL, an empty file is created.
 *
 * @note ltrace allowed functions: write, printf, strlen, putchar, puts, malloc, free, exit, open, read, write, close
 */

int create_file(const char *filename, char *text_content) {
    int fd;
    mode_t mode = FILE_MODE;

    if (filename == NULL) {
        perror("filename is NULL");
        return -1;
    }

    if (text_content == NULL) {
        fd = open(filename, O_CREAT | O_RDWR, mode);
        if (fd == -1) {
            perror("failed to create empty file");
            return -1;
        }
        close(fd);
        return 0;
    }

    fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, mode);
    if (fd == -1) {
        perror("failed to create file");
        return -1;
    }

    ssize_t written = write(fd, text_content, strlen(text_content));
    if (written != strlen(text_content)) {
        perror("failed to write to file");
        close(fd);
        return -1;
    }

    if (chmod(filename, mode) == -1) {
        perror("failed to set permissions");
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
}
