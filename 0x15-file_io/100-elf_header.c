#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * main - displays the information contained in the ELF header at the start of an ELF file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
    int fd, i;
    Elf64_Ehdr *header;

    if (argc != 2)
        dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]), exit(98);

    header = malloc(sizeof(Elf64_Ehdr));
    if (!header)
        dprintf(STDERR_FILENO, "Error: Unable to allocate memory\n"), exit(98);

    if (read(fd, header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
        dprintf(STDERR_FILENO, "Error: Unable to read ELF header\n"), exit(98);

    if (header->e_ident[0] != 0x7f || header->e_ident[1] != 'E' || header->e_ident[2] != 'L' || header->e_ident[3] != 'F')
        dprintf(STDERR_FILENO, "Error: Not an ELF file\n"), exit(98);

    printf("Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header->e_ident[i]);
    printf("\n");

    printf("Class:                             ");
    switch (header->e_ident[EI_CLASS])
    {
        case ELFCLASSNONE:
            printf("none\n");
            break;
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
    }

    printf("Data:                              ");
    switch (header->e_ident[EI_DATA])
    {
        case ELFDATANONE:
            printf("none\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
    }

    printf("Version:                           %d\n", header->e_ident[EI_VERSION]);

    printf("OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Solaris\n");
            break;
        case ELFOSABI_IRIX:
            printf("IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("Compaq TRU64 UNIX\n");
            break;
        case ELFOSABI_ARM:
            printf("ARM architecture\n");
            break;
        case ELFOSABI_STANDALONE:
            printf("Standalone (embedded) application\n");
            break;
        default:
            printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
    }

    printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    printf("Type:                              ");
    switch (header->e_type)
    {
        case ET_NONE:
            printf("NONE (No file type)\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        case ET_CORE:
            printf("CORE (Core file)\n");
            break;
        default:
            printf("<unknown: %x>\n", header->e_type);
    }

    printf("Entry point address:               %#lx\n", header->e_entry);

    printf("Start of program headers:          %lu (bytes into file)\n", header->e_phoff);

    printf("Format:                            ");
    switch (header->e_ident[EI_CLASS])
    {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
    }

    free(header);
    close(fd);
    return (0);
}
