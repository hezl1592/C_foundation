#include <stdio.h>

void print_time(int hour, int minute);

int main()
{
	int h=23;
	int m = 59;
	print_time(h, m);
	return 0;
}

void print_time(int hour, int minute)
{
	printf("Time: %d:%d\n", hour, minute);
}
