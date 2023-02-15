#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

char *_COLORS[] = {"\033[31m", "\033[32m", "\033[0m"};
char *_OUTPUT[] = {"KO", "OK"};

void print_tests(int len, int *arr)
{
	for (int i = 0; i < len; i++)
		printf("%s%s%s ", _COLORS[arr[i]], _OUTPUT[arr[i]], _COLORS[2]);
}

int *test_strjoin(void)
{
	char data[7][20][20] = {{"hello world!", "hello ", "world!"},
						{"", "", ""},
						{"\n", "", "\n"},
						{"\n", "\n", ""},
						{"\n", "", "\n"},
						{"a\n", "a", "\n"},
						{"\na", "\n", "a"}};
	int len = 7;
	int *out = (int *)malloc(len * sizeof(int));
	for (int i = 0; i < len; i++)
	{
		out[i] = strcmp(data[i][0], ft_strjoin(data[i][1], data[i][2]));
		if (out[i] != 0)
			out[i] = 0;
		else
			out[i] = 1;
	}
	printf("strjoin test:\t");
	print_tests(len, out);
	puts("");
	return (out);
}

void test_strlen(void)
{
	char arr[6][20] = {"hello world", \
						"", \
						"\n", \
						"\0", \
						" ", \
						"1234567890"};
	int out[6];
	for (int i = 0; i < 6; i++)
		out[i] = ft_strlen(arr[i]) == strlen(arr[i]);
	printf("strlen test:\t");
	print_tests(6, out);
	puts("");
}

void test_substr(void)
{
	char data[5][20][20] = {{"hello world!", "hello "},
						{"", ""},
						{"\n", "\n"},
						{"a\n", "a"},
						{"\na", "\n"}};
	int arr[5] = {6, 0, 1, 1, 1};
	int len = 5;
	int *out = (int *)malloc(len * sizeof(int));
	for (int i = 0; i < len; i++)
	{
		out[i] = strcmp(data[i][1], ft_substr(data[i][0], 0, arr[i]));
		if (out[i] != 0)
			out[i] = 0;
		else
			out[i] = 1;
	}
	printf("substr test:\t");
	print_tests(len, out);
	puts("");
}

void rewrite_file(int len, char *arr[len])
{
	int fd;
	remove("file.txt");
	fd = open("file.txt", O_CREAT, 0644);
	close(fd);
	fd = open("file.txt", O_WRONLY);
	for (int i = 0; i < len; i++)
		write(fd, arr[i], strlen(arr[i]));
	close(fd);
}

void reset_file(char *filename, char *str)
{
	int fd;
	remove(filename);
	fd = open(filename, O_CREAT, 0644);
	close(fd);
	fd = open(filename, O_WRONLY);
	write(fd, str, strlen(str));
	close(fd);
}

void test_get_next_line_(int fd, char *str, char *out)
{
	int p;
	char *get;
	get = get_next_line(fd);
	if (!out || !get)
		p = get == out;
	else
		p = (strcmp(get, out) == 0)? 1: 0;
	printf("get_next_line test:\t\t");
	printf("%s%s%s ", _COLORS[p], _OUTPUT[p], _COLORS[2]);
	puts("");
	close(fd);
}

void test_get_next_line_for_NULL(void)
{
	int fd;
	int out[2];
	char *arr[1] = {""};
	rewrite_file(1, arr);
	fd = open("file.txt", O_RDONLY);
	out[0] = (!get_next_line(fd))? 1: 0;
	out[1] = (!get_next_line(-1))? 1: 0;
	close(fd);
	printf("get_next_line test empty file:\t");
	print_tests(2, out);
	puts("");

}

void test_get_next_line_with_nl(void)
{
	int len = 5;
	char *arr[5] = {"hello world leha!\n",\
					"leha brat privet!\n",\
					"slomalsya\n",\
					"\n",
					"hello!\n"};
	int out[len];
	char *str;
	rewrite_file(len, arr);
	int fd = open("file.txt", O_RDONLY);
	for (int i = 0; i < len; i++)
	{
		str = get_next_line(fd);
		if (!str)
			out[i] = 0;
		else
			out[i] = (strcmp(arr[i], str) != 0)? 0: 1;
	}
	close(fd);
	printf("get_next_line test with nl:\t");
	print_tests(len, out);
	puts("");
}

void test_get_next_line_without_nl(void)
{
	int out[2];
	int fd;
	char *arr[1];

	arr[0] = "dfadskdfa dfa dmnf,asdn,mnfwehfeuh oplaldf; kaf ";
	rewrite_file(1, arr);
	fd = open("file.txt", O_RDONLY);
	out[0] = (strcmp(get_next_line(fd), arr[0]) != 0)? 0: 1;
	close(fd);

	arr[0] = " "; 
	rewrite_file(1, arr);
	fd = open("file.txt", O_RDONLY);
	out[1] = (strcmp(get_next_line(fd), arr[0]) != 0)? 0: 1;
	close(fd);

	printf("get_next_line test without nl:\t");
	print_tests(2, out);
	puts("");
}

void test_get_next_line(void)
{
	int fd;
	/* test_get_next_line_for_NULL(); */
	/* test_get_next_line_with_nl(); */
	/* test_get_next_line_without_nl(); */

	/* reset_file("file.txt", "hello leha\n"); */
	/* fd = open("file.txt", O_RDONLY); */
	/* test_get_next_line_(fd, "hello leha\n", "hello leha\n"); */
	/* close(fd); */

	/* reset_file("file.txt", "\n"); */
	/* fd = open("file.txt", O_RDONLY); */
	/* test_get_next_line_(fd, "\n", "\n"); */
	/* close(fd); */

	/* reset_file("file.txt", "\n\n\n"); */
	/* fd = open("file.txt", O_RDONLY); */
	/* test_get_next_line_(fd, "\n\n\n", "\n"); */
	/* close(fd); */


	/* test_get_next_line_(1000, " ", NULL); */
	/* test_get_next_line_(-1, " ", NULL); */
	/* test_get_next_line_(20, " ", NULL); */

	/* reset_file("file.txt", ""); */
	/* fd = open("file.txt", O_RDONLY); */
	/* test_get_next_line_(fd, "", NULL); */
	/* close(fd); */

	/* reset_file("file.txt", " "); */
	/* fd = open("file.txt", O_RDONLY); */
	/* test_get_next_line_(fd, " ", " "); */
	/* close(fd); */

	/* reset_file("file.txt", "hello world"); */
	/* fd = open("file.txt", O_RDONLY); */
	/* test_get_next_line_(fd, "hello world", "hello world"); */
	/* close(fd); */

	reset_file("file.txt", "hello world");
	fd = open("file.txt", O_RDONLY);
	puts(get_next_line(fd));
	puts(get_next_line(fd));
	close(fd);
}

int main()
{
	/* test_strlen(); */
	/* test_strjoin(); */
	/* test_substr(); */
	test_get_next_line();
	/* char *arr[1] = {"hello"} */
	/* int fd = open("file.txt", O_RDONLY); */
	
	
	return (0);
}
