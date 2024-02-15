#ifndef  MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>

#define EI_NIDENT 16
#define ELFCLASSNONE 0
#define ELFCLASS32 1
#define ELFCLASS64 2
#define ELFDATANONE 0
#define ELFDATA2LSB 1
#define ELFDATA2MSB 2
#define EI_CLASS (sizeof(uint8_t) * CHAR_BIT - 3)
#define EI_DATA (EI_CLASS + 1)
#define EI_VERSION (EI_DATA + 1)
#define EI_OSABI (EI_VERSION + 1)
#define EI_ABIVERSION (EI_OSABI + 1)
#define EI_PAD (EI_ABIVERSION + 1)
#define EI_TYPE (EI_PAD + 1)
#define EI_MACHINE (EI_TYPE + 1)
#define EI_VERSION1 (EI_MACHINE + 4)
#define EI_VERSION2 (EI_VERSION1 + 4)
#define EI_FLAGS (EI_VERSION2 + 4)
#define EI_EHSIZE (EI_FLAGS + 1)
#define EI_PHEENT (EI_EHSIZE + 2)
#define EI_PHNUM (EI_PHEENT + 2)
#define EI_SHNUM (EI_PHNUM + 2)
#define EI_SHSTRNDX (EI_SHNUM + 2)


typedef struct Elf64_Ehdr
{
    uint8_t e_ident[EI_NIDENT];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint32_t e_entry;
    uint32_t e_phoff;
    uint32_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Ehdr;

int create_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);
int append_text_to_file(const char *filename, char *text_content);
int main(int argc, char *argv[]);
int main(int argc, char *argv[]);


#endif
