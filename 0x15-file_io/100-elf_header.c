#include "main.h"

/**
 * main - displays the information contained in the ELF header at the start of an ELF file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on failure
 */
void print_error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(98);
}

void print_elf_header_info(Elf64_Ehdr *ehdr) {
    int i;
    printf("Magic:   ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", ehdr->e_ident[i]);
    }
    printf("\n");
    printf("Class:   %s\n", ehdr->e_ident[4] == 1 ? "ELF32" : "ELF64");
    printf("Data:    %s\n", ehdr->e_ident[5] == 1 ? "little endian" : "big endian");
    printf("Version: %d\n", ehdr->e_ident[6]);
    printf("OS/ABI:  %d\n", ehdr->e_ident[7]);
    printf("ABI Version: %d\n", ehdr->e_ident[8]);
    printf("Type:    %d\n", ehdr->e_type);
    printf("Entry point address: 0x%lx\n", ehdr->e_entry);
    printf("Format:  %d-bit\n", ehdr->e_ident[4] == 1 ? 32 : 64);
}

int main(int argc, char *argv[]) {
    int fd;
    Elf64_Ehdr ehdr;

    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        print_error("Error opening file");
    }

    if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr)) {
        print_error("Error reading ELF header");
    }

    if (ehdr.e_ident[0] != 0x7f || ehdr.e_ident[1] != 'E' || ehdr.e_ident[2] != 'L' || ehdr.e_ident[3] != 'F') {
        print_error("Not an ELF file");
    }

    print_elf_header_info(&ehdr);

    close(fd);
    return 0;
}
