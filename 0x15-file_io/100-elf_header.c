#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 64

typedef struct {
    unsigned char e_ident[16];
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

/**
 * print_error - Prints the error message with strerror
 * @message: The error message to print
 *
 * Return: void
 */
void print_error(const char *message)
{
    fprintf(stderr, "[Error] %s: %s\n", message, strerror(errno));
    exit(98);
}

/**
 * print_elf_header - Prints the information contained in the ELF header
 * @header: Pointer to the ELF header structure
 *
 * Return: void
 */
void print_elf_header(const Elf64_Ehdr *header)
{
    printf("ELF Header:\n");
    printf("  Magic:   ");
    
    int i;

    for (i = 0; i < 16; i++)
    {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %d-bit\n", (header->e_ident[4] == 1) ? 32 : 64);
    printf("  Data:                              %s\n", (header->e_ident[5] == 1) ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", header->e_ident[6]);
    printf("  OS/ABI:                            %u\n", header->e_ident[7]);
    printf("  ABI Version:                       %u\n", header->e_ident[8]);
    printf("  Type:                              %u\n", header->e_type);
    printf("  Entry point address:               %lx\n", header->e_entry);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 1 on incorrect usage, 98 on error
 */
int main(int argc, char *argv[])
{
	const char *filename;
       	if (argc != 2)
    {
        fprintf(stderr, "Usage: elf_header elf_filename\n");
        return (1);
    }

    filename = argv[1];
    int fd;

    Elf64_Ehdr header;
    ssize_t bytes_read;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        print_error("Failed to open file");
    }

    bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read == -1)
    {
        print_error("Failed to read file");
    }

    if (bytes_read != sizeof(header))
    {
        fprintf(stderr, "Error: Incomplete read of ELF header\n");
        return (98);
    }

    if (header.e_ident[0] != 0x7f || strncmp((char *)&header.e_ident[1], "ELF", 3) != 0)
    {
        fprintf(stderr, "Error: Not an ELF file\n");
        return (98);
    }

    print_elf_header(&header);

    close(fd);
    return (0);
}
