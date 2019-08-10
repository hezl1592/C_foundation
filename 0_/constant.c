#include <stdio.h>

int main()
{
	printf("hello world!\n");
	/*常量*/	
	printf("character:%c\ninteger:%d\nfloat:%f\n", '{', 34, 3.14);
	/*变量（声明可直接初始化）*/
	char firstletter;
	int hour, minute;
	float pi;
	/*赋值*/
	firstletter = 'a';
	hour=11;
	minute=59;
	pi=3.14;

	printf("Time is: %d:%d\n", hour, minute);
	return 0;
}
