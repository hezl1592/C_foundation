#include <stdio.h>

void foo(void)
{
	int i;
	printf("i: %d.\n", i);
	i = 777;
}

void foo1(void)
{
	int d;
	printf("d: %d.\n", d);
	d = 777;
}



int main()
{
	foo();
	foo();
	
	printf("next.\n");
	foo1();
	foo1();

	return 0;
}
