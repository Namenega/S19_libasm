/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:25:28 by namenega          #+#    #+#             */
/*   Updated: 2021/03/05 12:31:00 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main(void)
{
	int		fd;
	char	*buf = malloc(1024);
	char	*dest = malloc(sizeof(char) * 10);

	printf("\n---------------------------------------------\n");
	printf("		  FT_STRLEN");
	printf("\n---------------------------------------------\n");
	//strlen 1 char
	printf("\n[a]\nstrlen    : [%zu]\nft_strlen : [%zu]\n----------\n", strlen("a"), ft_strlen("a"));
	//strlen 1 string
	printf("[abcdefgh]\nstrlen    : [%zu]\nft_strlen : [%zu]\n----------\n", strlen("abcdefgh"), ft_strlen("abcdefgh"));
	//strlen 1 long string
	printf("[abcdefghijklmnopqrstuvwxyz] + à faire x10\nstrlen    : [%zu]\nft_strlen : [%zu]\n----------\n", strlen("abcdefghijklmnopqrstuvwxyz"), ft_strlen("abcdefghijklmnopqrstuvwxyz"));
	//strlen 1 empty string
	printf("[]\nstrlen    : [%zu]\nft_strlen : [%zu]\n", strlen(""), ft_strlen(""));
	printf("\n\n");

	printf("\n---------------------------------------------\n");
	printf("		  FT_STRCMP");
	printf("\n---------------------------------------------\n");
	// strcmp a < b
	printf("\n[abc] && [abcdef]\nstrcmp    : [%d]\nft_strcmp : [%d]\n----------\n", strcmp("abc", "abcdef"), ft_strcmp("abc", "abcdef"));
	// strcmp a = b
	printf("[abc] && [abc]\nstrcmp    : [%d]\nft_strcmp : [%d]\n----------\n", strcmp("abc", "abc"), ft_strcmp("abc", "abc"));
	// strcmp a > b
	printf("[abcdef] && [abc]\nstrcmp    : [%d]\nft_strcmp : [%d]\n----------\n", strcmp("abcdef", "abc"), ft_strcmp("abcdef", "abc"));
	// strcmp (empty)a & (empty)b
	printf("[] && []\nstrcmp    : [%d]\nft_strcmp : [%d]\n----------\n", strcmp("", ""), ft_strcmp("", ""));
	// strcmp (empty)a & b
	printf("[] && [abc]\nstrcmp    : [%d]\nft_strcmp : [%d]\n----------\n", strcmp("", "abc"), ft_strcmp("", "abc"));
	// strcmp a & (empty)b
	printf("[abc] && []\nstrcmp    : [%d]\nft_strcmp : [%d]\n----------\n", strcmp("abc", ""), ft_strcmp("abc", ""));
	// strcmp a != b
	printf("[abc] && [def]\nstrcmp    : [%d]\nft_strcmp : [%d]\n", strcmp("abc", "def"), ft_strcmp("abc", "def"));
	printf("\n\n");

	printf("\n---------------------------------------------\n");
	printf("		  FT_STRCPY");
	printf("\n---------------------------------------------\n");

	printf("\n[abcdef]\nstrcpy    : [%s]\nft_strcpy : [%s]\n----------\n", strcpy(dest, "abcdef"), ft_strcpy(dest, "abcdef"));
	printf("[]\nstrcpy    : [%s]\nft_strcpy : [%s]\n", strcpy(dest, ""), ft_strcpy(dest, ""));
	printf("\n\n");

	printf("\n---------------------------------------------\n");
	printf("		  FT_STRDUP");
	printf("\n---------------------------------------------\n");
	//strdup 1 string
	printf("\n[abcdef]\nstrdup    : [%s]\nft_strdup : [%s]\n----------", strdup("abcdef"), ft_strdup("abcdef"));
	//strdup 1 char
	printf("\n[a]\nstrdup    : [%s]\nft_strdup : [%s]\n----------", strdup("a"), ft_strdup("a"));
	//strdup 1 empty string
	printf("\n[]\nstrdup    : [%s]\nft_strdup : [%s]\n----------", strdup(""), ft_strdup(""));
	//strdup avec \0
	printf("\n[abc\\0def]\nstrdup    : [%s]\nft_strdup : [%s]\n", strdup("abc\\0def"), ft_strdup("abc\\0def"));
	printf("\n\n");

	printf("\n---------------------------------------------\n");
	printf("		  FT_WRITE");
	printf("\n---------------------------------------------\n");

	printf("\n[abcdef]\nwrite    : [%zd]\nft_write : [%zd]\n----------\n", write(1, "abcdef\n", 7), ft_write(1, "abcdef\n", 7));
	printf("\n[abc def]\nwrite    : [%zd]\nft_write : [%zd]\n----------\n", write(1, "abc def\n", 3), ft_write(1, "abc def\n", 3));
	printf("[]\nwrite    : [%zd]\nft_write : [%zd]\n", write(1, "", 0), ft_write(1, "", 0));
	printf("\n\n");

	printf("\n---------------------------------------------\n");
	printf("		  FT_READ");
	printf("\n---------------------------------------------\n");

	//syscall = 3 = read
	//syscall = 4 = write

	fd = open("./ft_strcpy.s", O_RDONLY);
	errno = 0;
	printf("\nread    :\tret = [%zd]\tbuf = [%s]\terrno = [%d]\n", read(fd, buf, 15), buf, errno);
	close(fd);
	fd = open("./ft_strcpy.s", O_RDONLY);
	errno = 0;
	printf("\nft_read :\tret = [%zu]\tbuf = [%s]\terrno = [%d]\n\n----------\n", ft_read(fd, buf, 15), buf, errno);
	close(fd);

	fd = -1;
	errno = 0;
	printf("\nread    :\tret = [%zd]\tbuf = [%s]\terrno = [%d]\n", read(fd, buf, 30), buf, errno);
	errno = 0;
	printf("\nft_read :\tret = [%zd]\tbuf = [%s]\terrno = [%d]\n\n", ft_read(fd, buf, 30), buf, errno);
	close(fd);
	return (0);
}
