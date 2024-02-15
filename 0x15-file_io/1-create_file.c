#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int create_file(const char *filename, char *text_content) {
    if (filename == NULL) {
        return -1;
    }
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        return -1;
    }
    if (text_content != NULL) {
        size_t len = strlen(text_content);
        ssize_t bytes_written = write(fd, text_content, len);
        if (bytes_written == -1 || (size_t)bytes_written != len) {
            close(fd);
            return -1;
        }
    }
    close(fd);
    return 1;
}
