#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

char *_COLORS[] = {"\033[31m", "\033[32m", "\033[0m"};
char *_OUTPUT[] = {"KO", "OK"};

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
	for (int i = 0; i < 7; i++)
		printf("%s%s%s ", _COLORS[out[i]], _OUTPUT[out[i]], _COLORS[2]);
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
	printf("strlen test:\t");
	for (int i = 0; i < 6; i++)
	{
		out[i] = ft_strlen(arr[i]) == strlen(arr[i]);
		printf("%s%s%s ", _COLORS[out[i]], _OUTPUT[out[i]], _COLORS[2]);
	}
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
	for (int i = 0; i < len; i++)
		printf("%s%s%s ", _COLORS[out[i]], _OUTPUT[out[i]], _COLORS[2]);
	puts("");
}

void test_get_next_line(void)
{
	int fd = open("file.txt", O_WRONLY | O_CREAT);

	int len = 5;
	int out[len];
	char *arr[5] = {"hello world leha!\n",\
					"leha brat privet!\n",\
					"slomalsya\n",\
					"\n",
					"hello!"};
	close(fd);
	fd = open("file.txt", O_RDONLY);
	for (int i = 0; i < len; i++)
		write(fd, arr[i], strlen(arr[i]));
	for (int i = 0; i < len; i++)
	{
		out[i] = strcmp(arr[i], get_next_line(fd));
		if (out[i] != 0)
			out[i] = 0;
		else
			out[i] = 1;
	}
	printf("get_next_line test:\t");
	for (int i = 0; i < len; i++)
		printf("%s%s%s ", _COLORS[out[i]], _OUTPUT[out[i]], _COLORS[2]);
	puts("");
	close(fd);
}

int main()
{
	/* test_strlen(); */
	/* test_strjoin(); */
	/* test_substr(); */
	/* test_get_next_line(); */

	/* int fd = open("file.txt", O_RDONLY); */
	/* char *out = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char)); */
	/* static char *buffer; */
	/* /1* buffer = read_line(fd, out, buffer); *1/ */
	/* /1* out = get_line(buffer); *1/ */
	/* out = get_next_line(fd); */
	/* out = get_next_line(fd); */
	/* out = get_next_line(fd); */
	/* out = get_next_line(fd); */
	/* out = get_next_line(fd); */
	/* printf("%lu\n", ft_strlen(out)); */
	/* printf("%s", out); */
	/* close(fd); */
	remove("file_empty.txt");
	int fd = open("file_empty.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	close(fd);
	fd = open("file_empty.txt", O_RDONLY);
	printf("%lu\n", read(fd, 0, 0));
	char *out = get_next_line(fd);
	if (!out)
		puts("NULL");
	else
		puts(out);
	return (0);
}
