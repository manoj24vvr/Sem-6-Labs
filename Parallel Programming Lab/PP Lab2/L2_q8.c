#include<stdio.h>
#include<omp.h>
#include<time.h>

int fib(int n)
{
    if (n <= 1)
	{
        return n;
    }
	
    return fib(n-1) + fib(n-2);
}

int main()
{
    int A[] = {10, 13, 5, 6};
    int n = sizeof(A) / sizeof(A[0]);
	int i;
	/*
		Sequential Execution
	*/

	printf("\n<========== Sequential Execution ==========>");
	printf("\nThe Fibonacci Numbers for the Array 'A'are:\n");

	clock_t t_seq = clock();

	for (i = 0; i < n; i++)
	{
        int fib_i = fib(A[i]);
        
        printf("Fibonacci(%d) = %d\n", A[i], fib_i);
    }
	printf("\n");

	t_seq = clock() - t_seq;
	double time_taken_seq = ((double)t_seq/CLOCKS_PER_SEC); // in seconds
	printf("\nThe Current Program took %f Milli seconds to execute!\n", (time_taken_seq)*1000);

	/*
		Parallel Execution
	*/

	printf("\n<========== Parallel Execution ==========>");
	printf("\nThe Fibonacci Numbers for the Array 'A'are:\n");

	clock_t t_par = clock();

    #pragma omp parallel for
    for (i = 0; i < n; i++)
	{
        int fib_i = fib(A[i]);
        printf("Fibonacci(%d) = %d\n", A[i], fib_i);
    }
	printf("\n");

	t_par = clock() - t_par;
	double time_taken_par = ((double)t_par/CLOCKS_PER_SEC); // in seconds
	printf("\nThe Current Program took %f Milli seconds to execute!\n", (time_taken_par)*1000);

	printf("\n<========== Performance Metrics ==========>\n");
	double speed_up = 0;
	speed_up = time_taken_seq /time_taken_par;
	printf("SpeedUp: %f\n", speed_up);

	double efficiency = 0;
	efficiency = speed_up/omp_get_num_procs();
	printf("Efficiency: %f\n", efficiency);

    return 0;
}
