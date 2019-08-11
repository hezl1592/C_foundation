#include <stdio.h>

void statement_switch(int condition);

int main()
{
	int con;
	con = 5;
	statement_switch(con);
	return 0; 
}

void statement_switch(int condition)
{
	switch(condition)
	{
		case 1:
			printf("1\n");
			break;
		case 2:
			printf("2\n");
			break;
		case 3:
			printf("3\n");
			break;
		case 4:
			printf("4\n");
			break; 
		default:
			printf("de\n");
			break;
	}
}
