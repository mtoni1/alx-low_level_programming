#include <stdio.h>
#include <stdlib.h>
#include "main.h"


/**
 * print_binary -  program that displays the information contained in the ELF header at the start of an ELF file.
 * @header: Displayed information
 * @read: a maximum of 2 times at runtime
 *
 *  Return: 1 on success and -1 on failure
 */


void print_elf_header(const Elf64_Ehdr *header) {
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    printf("Class:                             ");
    switch (header->e_ident[4]) {
        case 1:
            printf("ELF32\n");
            break;
        case 2:
            printf("ELF64\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    printf("Data:                              ");
    switch (header->e_ident[5]) {
        case 1:
            printf("little endian\n");
            break;
        case 2:
            printf("big endian\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    printf("Version:                           %d\n", header->e_ident[6]);

    printf("OS/ABI:                            ");
    switch (header->e_ident[7]) {
        case 0:
            printf("System V\n");
            break;
        case 3:
            printf("Linux\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    printf("ABI Version:                       %d\n", header->e_ident[8]);

    printf("Type:                              ");
    switch (header->e_type) {
        case 1:
            printf("REL (Relocatable file)\n");
            break;
        case 2:
            printf("EXEC (Executable file)\n");
            break;
        case 3:
            printf("DYN (Shared object file)\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    printf("Entry point address:               0x%lx\n", header->e_entry);

    printf("Start of program headers:          %lu (bytes into file)\n", header->e_phoff);

    printf("Format:                            ");
    switch (header->e_ident[4]) {
        case 1:
            printf("ELF32\n");
            break;
        case 2:
            printf("ELF64\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    printf("Number of program headers:         %d\n", header->e_phnum);

    printf("Size of program headers:           %d (bytes)\n", header->e_phentsize);

    printf("Start of section headers:          %lu (bytes into file)\n", header->e_shoff);

    printf("Number of section headers:         %d\n", header->e_shnum);

    printf("Size of section headers:           %d (bytes)\n", header->e_shentsize);

    printf("Section header string table index: %d\n", header->e_shstrndx);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
        return 98;
    }

    Elf64_Ehdr header;
    if (fread(&header, sizeof(header), 1, fp) != 1) {
        fprintf(stderr, "Error: Can't read ELF header from file %s\n", argv[1]);
        fclose(fp);
        return 98;
    }

    if (header.e_ident[0] != 0x7f || header.e_ident[1] != 'E' || header.e_ident[2] != 'L' || header.e_ident[3] != 'F') {
        fprintf(stderr, "Error: File %s is not an ELF file\n", argv[1]);
        fclose(fp);
        return 98;
    }

    print_elf_header(&header);

    fclose(fp);
    return 0;
}
