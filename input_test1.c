#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void cleanBuffer(char* buffer, int size);
void cleanBuffer(char* buffer, int size){
	int i = 0;
	while(i!=size-1){
		buffer[i] = '\0';
		i++;
	}
}
 int main(int argc, char *argv[]) 
{
    
    char* test = (char *)malloc(sizeof(char) * 100);
	cleanBuffer(test,100);
	test[0]= '0';
	test[1]= '1';
	test = '.'+test;

	
	printf("the test is: %s \n",test);
	
}
