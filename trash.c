#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void re(char **n)
{
	char *tmp;
	tmp = *n;
	*n = (char *)malloc(strlen("hello re!") * sizeof(char));
	strcpy(*n, "hello re!");
	free(tmp);
}

int main()
{
	char *n;
	n = (char *)malloc(strlen("hello world!") * sizeof(char));
	strcpy(n, "hello world!");
	puts(n);
	re(&n);
	puts(n);
	free(n);
	return (0);
}
