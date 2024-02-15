#ifndef CREATE_FILE_H
#define CREATE_FILE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

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
int create_file(const char *filename, char *text_content);

#endif 
