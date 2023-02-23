#include <stdio.h>
#include <omp.h> 
#include <time.h>
#define SIZE 10 
int main() {
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10};
	int even_sum = 0;
	int odd_sum = 0;
	clock_t start, end;
	start = clock();
	#pragma omp parallel shared(arr, even_sum, odd_sum) num_threads(2)
	{
		#pragma omp sections nowait
	  	{
   			#pragma omp section
   			{
	  			for (int i = 0; i < 10; i++) {
		 			if (arr[i] % 2 == 0) {
						even_sum += arr[i];
		 			}
	  			}
	  			int id = omp_get_thread_num();
	  			printf("Sum of even numbers: %d thread: %d\n", even_sum,id);
   			}
			#pragma omp section
		   	{
		  		for (int i = 0; i < 10; i++) {
			 		if (arr[i] % 2 != 0) {
						odd_sum += arr[i];
			 		}	
		  		}
		  		int id = omp_get_thread_num();
	  			printf("Sum of odd numbers: %d thread: %d\n", odd_sum,id);
	   		}
  		}
 	}
 	
 	end = clock();
		  
	double t_par = double(end-start)/CLOCKS_PER_SEC;
	printf("Execution time: %f\n", t_par);
	
	return 0;
}
