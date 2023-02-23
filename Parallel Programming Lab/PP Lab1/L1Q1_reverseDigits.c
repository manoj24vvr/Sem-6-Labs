#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(){
	
	clock_t time;
    
	int a[9], b[9], i;
	printf("Enter the elements of the array: ");
	for(i=0; i<9; i++){
		scanf("%d", &a[i]);
	}
	
    time = clock();

	for(i=0; i<9; i++){
		int num = 0;
		while(a[i] != 0){
			int last_dig = a[i] % 10;
			a[i] = a[i] / 10;
			num = num*10 + last_dig;
		}
		b[i] = num;		
	}
	

	printf("Elements after the numbers the reversed are: ");
	for(i=0; i<9; i++){
		printf("%d  ", b[i]);
	}
	
    time = clock() - time;
    double time_spent = (double)(time) / CLOCKS_PER_SEC;	
	printf("\n\nTime taken to execute: %f \n", time_spent);
	
	return 0;
}
