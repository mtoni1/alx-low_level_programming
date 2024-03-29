#ifndef  MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdint.h>
#include <errno.h>
#include <elf.h>
#include <sys/wait.h>



int create_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);
int append_text_to_file(const char *filename, char *text_content);
int main(int argc, char *argv[]);
void print_elf_header(Elf64_Ehdr *header);
void print_error(char *msg);

#endif
