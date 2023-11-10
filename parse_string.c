#include "shell.h"
/**
 * parse_string - break input string into pieces
 *
 * @input_line: input string
 *
 * Return: array of broken down string (commands)
 */
char **parse_string(char *input_line)
{
	char **arr_str;
	char *token;
	int i_idx = 0;

	arr_str = malloc(8 * sizeof(char *));

	if (arr_str == NULL)
		perror("failed to allocate memory"), exit(1);

	while ((token = strtok(input_line, " \t\n\"")) != NULL)
	{
		if (token[0] == '"')
		{
			_memmove(token, token + 1, _my_strlen(token));
			token[_my_strlen(token) - 1] = '\0';
		}
		if (*token != '\0')
		{
		arr_str[i_idx] = _my_strdup(token);
		if (arr_str[i_idx] == NULL)
			perror("failed to allocate memory"), exit(1);
		i_idx++;
		}
		input_line = NULL;
	}

	arr_str[i_idx] = NULL;
	return (arr_str);
}

/**
 * _memmove - used to copy a block of memory from one location to another
 * itis similer to memcpy function
 * @dest: copied cout of bytes
 * @src: the source
 * @count: count
 * Return: pointer to the destination memory block
 */
void *_memmove(void *dest, const void *src, size_t count)
{
	unsigned char *dest_ = dest;
	const unsigned char *src_ = src;

	if (dest_ == src_)
	{
		return (dest_);
	}

	if (src_ < dest_ && dest_ < src_ + count)
	{
		src_ = src_ + count;
		dest_ = dest_ + count;

		while (count--)
		{
			*(--dest_) = *(--src_);
		}
	}
	else
	{
		while (count--)
		{
			*dest_++ = *src_++;
		}
	}

	return (dest);
}

