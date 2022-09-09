#include "main.h"
/**
 *  _prerror - Print Custome Error
 * @argv:Program Name
 * @c:Error Count
 * @cmd:Command
 * Return: Void
 */
void _prerror(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	PRINT(argv[0]);
	PRINT(" : ");
	PRINT(er);
	PRINT(": ");
	PRINT(cmd[0]);
	PRINT(": Illegal number: ");
	PRINT(cmd[1]);
	PRINT("\n");
	free(er);
}
