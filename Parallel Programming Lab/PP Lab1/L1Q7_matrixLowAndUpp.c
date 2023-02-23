#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

int main(){
	
	clock_t time;
    
	int m=5;
	int i, j, A[m][m], B[m][m];
	printf("Enter the elements of matrix A: ");
	for(i=0; i<m; i++){
		for(j=0; j<m; j++){
			scanf("%d", &A[i][j]);
		}
	}
		
    time = clock();


	int max[m], min[m]; // max and min are arrays with maximum and minimum values of each row in the matrix
	for(i=0;i<m;i++){
		max[i] = A[i][0];
		min[i] = A[i][0];

	}
	for(i=0; i<m;i++){
		for(j=0; j<m;j++){
			if(A[i][j] > max[i]){
				max[i] = A[i][j];
			}
			
		}
	}
	for(i=0; i<m;i++){
		for(j=0; j<m;j++){
			if(A[i][j] < min[i]){
				min[i] = A[i][j];
			}
		}
	}
	printf("\n\nMax values of each row: ");
	for(i=0;i<m;i++){
		printf("%d  ", max[i]);
	}
	printf("\n\nMin values of each row: ");
	for(i=0;i<m;i++){
		printf("%d  ", min[i]);
	}
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			if(i == j){
				B[i][j] = 0;
			}
			if(i < j){
				B[i][j] = min[i];
			}
			else if(i > j){
				B[i][j] = max[i];
			}
		}
	}
	printf("\n\nMatrix A: \n");
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			printf("%d  ", A[i][j]);
		}
		printf("\n\n");
	}
	printf("\n\nMatrix B: \n");
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			printf("%d  ", B[i][j]);
		}
		printf("\n\n");
	}
	
    time = clock() - time;
    double time_spent = (double)(time) / CLOCKS_PER_SEC;	
	printf("\n\nTime taken to execute: %f \n", time_spent);
	
	return 0;
	
}
