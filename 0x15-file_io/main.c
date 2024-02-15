#include <stdio.h>
#include "main.h"

int main(void) {
    int rc;
    const char *filename = "test_file.txt";
    const char *text_content = "Hello World!\n";

    rc = create_file(filename, text_content);
    if (rc != 0) {
        fprintf(stderr, "create_file() failed: %d\n", rc);
        return 1;
    }

    printf("File '%s' created successfully.\n", filename);

    return 0;
}
