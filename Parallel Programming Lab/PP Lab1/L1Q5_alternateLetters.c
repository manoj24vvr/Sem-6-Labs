#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

int main(){
	
	clock_t time;
    
	char s1[20], s2[20];
	int i;
	printf("Enter 1st string: ");
	scanf("%s", s1);  
	printf("Enter 2nd string: ");
	scanf("%s", s2);
	
    time = clock();

	int l1 = strlen(s1);
	int l2 = strlen(s2);
	if(l1 != l2){
		printf("String length's are unequal. Please give strings of equal length'");
	}else{
		for(i=0;i<l1; i++){
			printf("%c", s1[i]);
			printf("%c", s2[i]);
		}
	}
    time = clock() - time;
	
    double time_spent = (double)(time) / CLOCKS_PER_SEC;	
	printf("\n\nTime taken to execute: %f \n", time_spent);
	
	return 0; 
}
