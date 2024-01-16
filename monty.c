#include "monty.h"
/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 always success
 */

int main(int argc, char *argv[])
{
	(void)argv;
	/* Variables here */

	/* Code to open and read file, and execute instructions */
	/* Example: */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* More code to handle the file and process instructions */
	/* Be sure to call kf_push and kf_pall where needed */
	return (0);
}
