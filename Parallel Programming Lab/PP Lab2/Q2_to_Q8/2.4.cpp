#include <stdio.h>
#include <omp.h> 
int main() {
	int a = 4;
	int b = 2;
 
	#pragma omp parallel shared(a,b)
	{
	 #pragma omp sections nowait
	 {
		 	
   		#pragma omp section
   		{
	  		int sum = a + b;
	  		printf("Addition: %d + %d = %d (thread %d)\n", a, b, sum, omp_get_thread_num());
   		}
		#pragma omp section
   		{
	  		int difference = a - b;
	  		printf("Subtraction: %d - %d = %d (thread %d)\n", a, b, difference, omp_get_thread_num());
   		}
		#pragma omp section
   		{
	  		int product = a * b;
	  		printf("Multiplication: %d * %d = %d (thread %d)\n", a, b, product, omp_get_thread_num());
   		}
		#pragma omp section
   		{
	  		int quotient = a / b;
	  		int remainder = a % b;
	  		printf("Division: %d / %d = %d with a remainder of %d (thread %d)\n", a, b, quotient, remainder, omp_get_thread_num());
   		}
	}
  }
	return 0;
}
