#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

int main(){
	
	clock_t time;
    
	int i, j, vlen, m, n;
	printf("Enter no. of elements in the vector: ");
	scanf("%d", &vlen);
	printf("Enter the no. of rows and columns of the matrix: ");
	scanf("%d %d", &m, &n);

	int mat[m][n], product[m], vector[vlen];
	if(vlen != n){
		printf("Length of vector and no. of columns in the matrix must be same for the multiplication.");
	}else{
		printf("Enter the elements of the vector: ");
		for(i=0; i<vlen; i++){
			scanf("%d", &vector[i]);
		}
		printf("Enter the elements of the matrix: ");
		for(i=0; i<m;i++){
			for(j=0;j<n;j++){
				scanf("%d", &mat[i][j]);
			}
		}
	}
				
    time = clock();


	for(i=0; i<m; i++){
		product[i] = 0;
		for(j=0; j<n; j++){
			product[i] = product[i] + mat[i][j]*vector[j];
		}
	}
	
	
	printf("Final product of matrix and vector is: ");
	for(i=0;i<m;i++){
		printf("%d \n", product[i]);
	}
    time = clock() - time;
	
    double time_spent = (double)(time) / CLOCKS_PER_SEC;	
	printf("\n\nTime taken to execute: %f \n", time_spent);
	
	return 0;
}
