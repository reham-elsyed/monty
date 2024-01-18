#include "monty.h"
/**
 * _get_tok_num - get token num
 * @str: input string
 * @sep: input seperator
 * Return: number of tokens
 */
int _get_tok_num(char *str)
{
        int token_num = 0;
        char *token, *str_cpy;

        str_cpy = strdup(str);
        if (str_cpy == NULL)
                return (-1);
        token = strtok(str_cpy, " \n\t");
        while (token != NULL)
        {
                token_num++;
                token = strtok(NULL, " \n\t");
        }
        free(str_cpy);
        return (token_num);
}
/**
 * _split - function string splitter
 * @str: input string
 * @sep: input seperator
 * Return: array of splitted strings
 */
char **_split(char *str)
{
        int i, token_num = 0;
        char **result, *token, *str_cpy;

        token_num = get_tok_num(str);
        if (token_num == -1)
                return (NULL);
        result = malloc(sizeof(char *) * (token_num + 1));
        if (result == NULL)
        {
                perror("split error");
                return (NULL);
        }
        str_cpy = strdup(str);
        if (str_cpy == NULL)
        {
                free(result);
                return (NULL);
        }
        token = strtok(str_cpy, " \n\t");
        for (i = 0; token != NULL; i++)
        {
                result[i] = strdup(token);
                if (result[i] == NULL)
                {
                        for (i = i - 1; i >= 0; i--)
                                free(result[i]);
                        free(result);
                        return (NULL);
                }
                token = strtok(NULL, " \n\t");
        }
        result[i] = NULL;
        free(str_cpy);
        return (result);
}

/**
 * strdup - string dublicate
 * @str: input string
 * Return: duplicate pointer
 */
char *strdup(char *str)
{
	int str_len = strlen(str);
	int i;
	char *str_dub = malloc(sizeof(char) * (str_len + 1));

	if (str_dub == NULL)
	{
		free(str_dub);
		perror("string dublicate error");
		return (NULL);
	}
	for (i = 0; i < str_len; i++)
		str_dub[i] = str[i];
	str_dub[i] = '\0';
	return (str_dub);
}
