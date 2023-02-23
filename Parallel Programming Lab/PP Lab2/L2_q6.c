#include<stdio.h>
#include<omp.h>
#include<time.h>

int isPrime(int a)
{
	if(a == 1)
		return 0;
	if(a == 2)
		return 1;
	
	int i;
	
	for(i=a-1; i>1; i--)
	{
		if(a%i == 0)
			return 0;
	}
	
	return 1;
}

int main()
{
	int a, b, i;
	int num_threads;
	
	printf("Enter the Starting and Ending numbers for generating Primes:\n");
	scanf("%d%d", &a, &b);
	
	/*
		Sequential Execution
	*/
	
	printf("\n<========== Sequential Execution ==========>");
	printf("\nThe Prime Numbers b/w %d & %d are: ", a, b);
	
	clock_t t_seq = clock();
	
	for(i=a; i<=b; i++)
	{
		if(isPrime(i))
			{
				printf("%d ", i);
			}
	}
	printf("\n");
	
	t_seq = clock() - t_seq;
	double time_taken_seq = ((double)t_seq/CLOCKS_PER_SEC); // in seconds
	printf("\nThe Current Program took %f Milli seconds to execute!\n", (time_taken_seq)*1000);
	
	/*
		Parallel Execution
	*/
	
	printf("\n<========== Parallel Execution ==========>");
	printf("\nThe Prime Numbers b/w %d & %d are: ", a, b);
	
	clock_t t_par = clock();
	
	#pragma omp parallel shared(num_threads)
	{
		int id = omp_get_thread_num();
		int num_th  = omp_get_num_threads();
		num_threads = num_th; 
		int i;
		for(i=a+id; i<=b; i=i+num_th)
		{
			if(isPrime(i))
			{
				printf("%d ", i);
			}
		}
	}
	printf("\n");
	
	t_par = clock() - t_par;
	double time_taken_par = ((double)t_par/CLOCKS_PER_SEC); // in seconds
	printf("\nThe Current Program took %f Milli seconds to execute!\n", (time_taken_par)*1000);

	printf("\nPerformance Metrics:\n");
	double speed_up = 0;
	speed_up = time_taken_seq /time_taken_par;
	printf("SpeedUp: %f\n", speed_up);

	double efficiency = 0;
	efficiency = speed_up/num_threads;
	printf("Efficiency: %f\n", efficiency);

	return 0;
}
