#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(){
	
	clock_t time;
    
	int A, B;
	printf("Enter the values of A and B: ");
	scanf("%d %d", &A, &B);
	
    time = clock();

	int sum = A+B;
	int diff = A-B;
	int mul = A*B;
	int div = A/B;

	printf("Sum: A + B= %d \n\n", sum);
	printf("Difference: A - B= %d \n\n", diff);
	printf("Product: A * B= %d \n\n", mul);
	printf("Division: of A / B= %d \n\n", div);
	
	time = clock() - time;
    double time_spent = (double)(time) / CLOCKS_PER_SEC;	
	printf("\n\nTime taken to execute: %f \n", time_spent);

	
	return 0;
}
