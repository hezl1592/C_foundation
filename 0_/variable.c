#include <stdio.h>

/*Global variable*/
int hour=12;
int minute=59;

void print_time();

int main()
{
	int hour = 23;
	int minute = 59;
	
	print_time();

	/*语句块中的局部变量*/
	{
		int hour = 22;
		int minute = 59;
		printf("Time :%d:%d\n", hour, minute);
	}
	
	printf("Time :%d:%d\n", hour, minute);

	return 0;
}

void print_time()
{
	printf("Time :%d:%d\n", hour, minute);
}
