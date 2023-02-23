#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include <time.h>
#include<math.h>
int main()
{
	clock_t start, end;
	double t_par, i;
	double result;
	double t_seq;
	start = clock();
	/*
	for(i = 1; i <= 3; i++)
	{
		double x = omp_get_thread_num();
		result = pow(i, x);
		printf("%lf ", result);
	}
	end = clock();
	t_seq = ((double)(end - start)) / CLOCKS_PER_SEC;
	*/

	printf("\n");
	start = clock();
	
#pragma omp parallel num_threads(5)
	{	
		int x = omp_get_thread_num();
		double i = 0;
		for (i = 1; i <= 3; i++)
		{
			result = pow(i, x);
			printf("%lf ", result);
		}
	}
	end = clock();
	t_par = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\nTime taken for sequential execution:%f\n", t_seq);
	printf("Time taken for parallel execution:%f\n", t_par);

	double speed_up = 0;
	speed_up = (t_seq) / (t_par);
	printf("SpeedUp:%f\n", speed_up);

	double efficiency = 0;
	int num_threads = 8;
	efficiency = (speed_up) / (num_threads);
	printf("Efficiency:%f\n", efficiency);


	return 0;
}
