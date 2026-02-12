/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <ckarsent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:08:40 by ckarsent          #+#    #+#             */
/*   Updated: 2026/02/12 14:06:40 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/nm.h"

#define C_RESET   "\033[0m"

#define C_RED     "\033[31m"
#define C_GREEN   "\033[32m"
#define C_YELLOW  "\033[33m"
#define C_BLUE    "\033[34m"
#define C_MAGENTA "\033[35m"
#define C_CYAN    "\033[36m"
#define C_GRAY    "\033[90m"

#include <stdio.h>

static int is_elf(unsigned char *p, size_t size)
{
	if (size < 4)
		return 0;
	return (p[EI_MAG0] == ELFMAG0 && p[EI_MAG1] == ELFMAG1 && p[EI_MAG2] == ELFMAG2 && p[EI_MAG3] == ELFMAG3);
}

static int ft_sym(Elf64_Shdr *shdr, void *map, size_t size, int sym_i)
{
	(void)size;
	(void)sym_i;
	size_t		count;
	Elf64_Shdr	symsec;
	Elf64_Sym 	*sym;

	symsec = shdr[sym_i];
	count = symsec.sh_size / symsec.sh_entsize;
	sym = (Elf64_Sym *)((char *)map + symsec.sh_offset);
	int str_idx = symsec.sh_link;
	Elf64_Shdr strsec = shdr[str_idx];
	char *strtab = (char *)map + strsec.sh_offset;
	for (size_t j = 0; j < count; j++)
	{
    	Elf64_Sym *s = &sym[j];

		if (s->st_name >= strsec.sh_size)
			continue;

		char *name = strtab + s->st_name;
		if (name[0] == '\0')
			continue;

		printf(C_GREEN "%016lx " C_RESET "%s\n", (unsigned long)s->st_value, name);
	}
	return (0);
}

static int ft_dyn(void *map, size_t size, int dyn_i)
{
	(void)map;
	(void)size;
	(void)dyn_i;
	return (0);
}

static int parse_elf64(void *map, size_t size, char *file)
{
	Elf64_Ehdr *ehdr;
	Elf64_Shdr *shdr;
	Elf64_Shdr shstr_sec;
	char       *shstrtab;
	size_t      sh_table_size;
	int         sym_i = -1;
	int         dyn_i = -1;

	if (size < sizeof(Elf64_Ehdr))
		return (1);

	ehdr = (Elf64_Ehdr *)map;

	if (ehdr->e_shentsize != sizeof(Elf64_Shdr))
		return (1);

	if (ehdr->e_shoff > size)
		return (1);

	sh_table_size = (size_t)ehdr->e_shnum * sizeof(Elf64_Shdr);
	if (ehdr->e_shoff + sh_table_size > size)
		return (1);

	if (ehdr->e_shstrndx >= ehdr->e_shnum)
		return (1);

	shdr = (Elf64_Shdr *)((char *)map + ehdr->e_shoff);

	shstr_sec = shdr[ehdr->e_shstrndx];
	if (shstr_sec.sh_offset > size)
		return (1);
	if (shstr_sec.sh_offset + shstr_sec.sh_size > size)
		return (1);

	shstrtab = (char *)map + shstr_sec.sh_offset;

	printf(C_MAGENTA "%s: ELF64\n\n" C_RESET, file);

	for (int i = 0; i < (int)ehdr->e_shnum; i++)
	{
		char *name = "<bad name>";

		if (shdr[i].sh_name < shstr_sec.sh_size)
			name = shstrtab + shdr[i].sh_name;

		printf(C_CYAN "[%2d] " C_RESET "%s\n", i, name);

		if (name[0] != '<')
		{
			if (ft_strcmp(name, ".symtab") == 0)
				sym_i = i;
			else if (ft_strcmp(name, ".dynsym") == 0)
				dyn_i = i;
		}
	}
	printf("\n");
	//int use_i = -1;
	if (sym_i != -1)
		return (ft_sym(shdr, map, size, sym_i));
	else if (dyn_i != -1)
		return (ft_dyn(map, size, dyn_i));
	else
		return (0);

	return (0);
}

static int parse_elf32(void *map, size_t size, const char *file)
{
	(void)map;
	(void)size;
	printf("%s: ELF32 (not implemented yet)\n", file);
	return (1);
}

static int dispatch(void *map, size_t size, char *file)
{
	unsigned char *p = (unsigned char *)map;

	if (!is_elf(p, size))
		return (1);

	if (size < EI_NIDENT)
		return (1);

	if (p[EI_CLASS] == ELFCLASS64)
		return (parse_elf64(map, size, file));

	if (p[EI_CLASS] == ELFCLASS32)
		return (parse_elf32(map, size, file));

	return (1);
}

int read_file(char *file)
{
	int         fd;
	void        *map;
	struct stat st;
	int         d;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);

	if (fstat(fd, &st) < 0)
		return (close(fd), 1);

	if (st.st_size == 0)
		return (close(fd), 1);

	map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (map == MAP_FAILED)
		return (close(fd), 1);

	d = dispatch(map, (size_t)st.st_size, file);

	munmap(map, st.st_size);
	close(fd);
	return (d);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (read_file("a.out"));

	for (int i = 1; i < argc; i++)
	{
		read_file(argv[i]);
		if (i != argc - 1)
			printf(C_YELLOW "\n\n##################################################\n\n\n" C_RESET);
	}
	return (0);
}

//gcc srcs/main.o -shared -o test.so

//Dans ELF, st_info contient un “type” (ELF64_ST_TYPE), et pour un symbole fichier c’est STT_FILE.
//ne pas afficher
//si ELF64_ST_TYPE(sym->st_info) == STT_FILE → skip
