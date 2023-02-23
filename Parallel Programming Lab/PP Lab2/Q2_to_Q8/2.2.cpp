#include <stdio.h>
#include <omp.h>
#include<math.h>

int main(){
	
	omp_set_num_threads(5);
	#pragma omp parallel
	{
		int i = 2;
		int x = omp_get_thread_num();
		int p = pow(i, x);
		printf("The value of i^x for thread id %d is %d\n", x, p);
	}
}
