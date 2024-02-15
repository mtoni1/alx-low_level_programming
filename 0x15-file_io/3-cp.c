#include <stdio.h>
#include <stdlib.h>
#include "main.h"


/**
 * 3-cp - program that copies the content of a file to another file
 * @n: number to print
 * @buffer:  must read 1,024 bytes at a time from the file_from to make less system calls.
 * 
 *  Return: 1 on success and -1 on failure
 */


int copy_file(const char *src_filename, const char *dest_filename) {
    if (src_filename == NULL || dest_filename == NULL) {
        return 97;
    }

    FILE *src_file = fopen(src_filename, "rb");
    if (src_file == NULL) {
        perror("Error: Can't read from file");
        return 98;
    }

    FILE *dest_file = fopen(dest_filename, "wb");
    if (dest_file == NULL) {
        fclose(src_file);
        perror("Error: Can't write to file");
        return 99;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, src_file)) > 0) {
        if (fwrite(buffer, sizeof(char), bytes_read, dest_file) != bytes_read) {
            perror("Error: Can't write to file");
            fclose(src_file);
            fclose(dest_file);
            return 99;
        }
    }

    if (ferror(src_file) != 0) {
        perror("Error: Can't read from file");
        fclose(src_file);
        fclose(dest_file);
        return 98;
    }

    if (ferror(dest_file) != 0) {
        perror("Error: Can't write to file");
        fclose(src_file);
        fclose(dest_file);
        return 99;
    }

    if (fclose(src_file) != 0) {
        perror("Error: Can't close src_file");
        fclose(dest_file);
        return 100;
    }

    if (fclose(dest_file) != 0) {
        perror("Error: Can't close dest_file");
        return 100;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s file_from file_to\n", argv[0]);
        return 97;
    }

    int result = copy_file(argv[1], argv[2]);
    if (result != 0) {
        switch (result) {
            case 97:
                printf("Usage: %s file_from file_to\n", argv[0]);
                break;
            case 98:
                printf("Error: Can't read from file %s\n", argv[1]);
                break;
            case 99:
                printf("Error: Can't write to file %s\n", argv[2]);
                break;
            case 100:
                printf("Error: Can't close fd %d\n", errno);
                break;
            default:
                printf("Error: Unknown error\n");
                break;
        }
    } else {
        printf("File copied successfully\n");
    }

    return 0;
}
