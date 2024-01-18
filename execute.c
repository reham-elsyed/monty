#include"monty.h"

instruction_t op[] = {
	{"push", &push}
};


int execute(char **token, stack_t **stack, FILE *file)
{
	unsigned int i = 0;

	while(token && token[i])
	{
		for (; i < sizeof(op) / sizeof(instruction_t); ++i)
		{
		if (strcmp(op[i].opcode, token[i]) == 0)
		{
			op[i].f(stack, line_number, token[i + 1]);
			break;
		}
	}
}
return (0);
}
