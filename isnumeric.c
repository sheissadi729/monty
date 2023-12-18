#include "monty.h"
/**
 * isnumeric - checks if a string is a number
 * @str: string
 * Return: true if number false otherwise
 */
bool isnumeric(const char *str)
{
	while(*str != '\0')
	{
		if(!isdigit(*str))
		{
			return false;
		}
		str++;                
	}
	return true;
}	
