#include <stdio.h>

void statements_if(int condition);
void statements_if_else(int condition);

int main()
{
	int condition=1; 
	
	statements_if(condition); 
	statements_if_else(condition);  
	return 0;
}

void statements_if(int condition)
{ 
	printf("if statement: \n");
	if(condition) printf("Yes!\n");
}

void statements_if_else(int condition)
{
	printf("if_else statement: \n");
	if(condition != 1) printf("Yes!\n");
	else printf("No!\n"); 
}
