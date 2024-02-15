#ifndef ELF_UTILS_H
#define ELF_UTILS_H

#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h> // For O_APPEND
#include <unistd.h> // For close()
#include <errno.h>



#define EI_NIDENT 16
#define BUFFER_SIZE 1024

typedef struct {
    unsigned char e_ident[EI_NIDENT];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Ehdr;

void print_elf_header(const Elf64_Ehdr *header);
int copy_file(const char *src_filename, const char *dest_filename);
int append_text_to_file(const char *filename, char *text_content);
int create_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);

#endif /* ELF_UTILS_H */
