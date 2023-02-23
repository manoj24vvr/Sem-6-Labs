#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

int main(){
	
	clock_t time;
    
	char str[10];
	int i, j;
	printf("Enter the string: ");
	scanf("%s", &str);
	
    time = clock();

	for(i=0;str[i]!='\0';i++){
		char c= str[i];
		for(j=0; j<i+1; j++){
			printf("%c", str[i]);
		}
	}	
	
    time = clock() - time;
    double time_spent = (double)(time) / CLOCKS_PER_SEC;	
	printf("\n\nTime taken to execute: %f \n", time_spent);
	
	return 0;
}
