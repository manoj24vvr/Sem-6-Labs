#include<stdio.h>
#include<string.h>
#include<time.h>

char toggle_char(char p)
{
	int a = (int)(p);

	if(a<97)
	{
		a = a+32;
	}
	else
	{
		a = a-32;
	}
	
	return ((char)(a));
}

int main()
{
	char str[100];
	int no_of_threads;

	printf("Enter the String: ");
	scanf("%[^\n]%*c", str);
	
	/*
		Sequential Execution
	*/
	
	printf("\n<========== Sequential Execution ==========>");
	
	clock_t t_seq = clock();
	int i;
	for(i=0; i<strlen(str); i++)
	{
		char temp = toggle_char(str[i]);

		str[i] = temp;
	}

	t_seq = clock() - t_seq;

	printf("\nThe Resultant String is: ");
	for(i=0; i<strlen(str); i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");
	
	double time_taken_seq = ((double)t_seq/CLOCKS_PER_SEC); // in seconds
	printf("\nThe Current Program took %f Milli seconds to execute!\n", (time_taken_seq)*1000);
	
	/*
		Parallel Execution
	*/
	
	printf("\n<========== Parallel Execution ==========>");
	
	clock_t t_par = clock();
	
	#pragma omp parallel shared(no_of_threads) //num_threads(4) 
	{
		int id = omp_get_thread_num();
		int num_th  = omp_get_num_threads();
		no_of_threads = num_th; 
		
		for(i=0; i<strlen(str); i=i+num_th)
		{
			char temp = toggle_char(str[i]);

			str[i] = temp;
		}
	}
	printf("\n");
	
	t_par = clock() - t_par;
	
	printf("\nThe Resultant String is: ");
	for(i=0; i<strlen(str); i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");

	double time_taken_par = ((double)t_par/CLOCKS_PER_SEC); // in seconds
	printf("\nThe Current Program took %f Milli seconds to execute!\n", (time_taken_par)*1000);

	printf("\nPerformance Metrics:\n");
	double speed_up = 0;
	speed_up = time_taken_seq /time_taken_par;
	printf("SpeedUp: %f\n", speed_up);

	double efficiency = 0;
	efficiency = speed_up/no_of_threads;
	printf("Efficiency: %f\n", efficiency);

	return 0;
}
