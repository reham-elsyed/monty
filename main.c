#include "monty.h"

/**
 * main -function main
 * @argc: input num
 * @argv: pointer to input array
 * Return: int
 */

int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	char **tokens;
	size_t len = 0;
	ssize_t nread, status = 1;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s ,<file>.\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		tokens = _split(line);
		printf("slines parsed back to main");
		execute(tokens, stack_t, file);
		}
	free(line);
	fclose(stream);
	exit(0);
}
