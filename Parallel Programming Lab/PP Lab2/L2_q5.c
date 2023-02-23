#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include <time.h>
#include<math.h>


int main()
{
	int i;
	
	clock_t start, end;
	double t_seq, t_par;

	int n;
	printf("Enter the size of the vectors a and b: \n");
	scanf("%d", &n);

	int vector_a[10];
	int vector_b[10];

	printf("Enter the elements of a: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &vector_a[i]);
	}

	printf("Enter the elements of b: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &vector_b[i]);
	}
	
	printf("Sequential Execution\n");
	start = clock();
	
	/*
		sequntial logic
	*/
	
	/* Addition */
	printf("Addition of two vectors a and b: \n");
	for (i = 0; i < n; i++) {

		printf("%d  ", (vector_a[i] + vector_b[i]));

	}printf("\n");

	/* Subtraction */
	printf("Subtraction of two vectors a and b: \n");
	for (i = 0; i < n; i++) {

		printf("%d  ", (vector_a[i] - vector_b[i]));

	}printf("\n");

	/* Multiplication */
	printf("Multiplication of two vectors and b: \n");
	for (i = 0; i < n; i++) {

		printf("%d  ", (vector_a[i] * vector_b[i]));

	}printf("\n");
	/* Division */
	printf("Division of two vectors a and b: \n");
	for (i = 0; i < n; i++) {

		printf("%0.2f  ", (double)vector_a[i] / vector_b[i]);

	}printf("\n");

	end = clock();
	t_seq = ((double)end - start) / CLOCKS_PER_SEC;

	printf("Parallel Execution\n");

	start = clock();

	#pragma omp parallel num_threads(4)
	{
		int id = omp_get_thread_num(), i;   // thread-id
		int total_thread = omp_get_num_threads();

		switch (id % 4) {
		case 0:
			/* Addition */
			printf("Addition of two vectors a and b: \n");
			for (i = 0; i < n; i++) {

				printf("%d  ", (vector_a[i] + vector_b[i]));

			}printf("\n");
			break;
		case 1:
			/* Subtraction */
			printf("Subtraction of two vectors a and b: \n");
			for (i = 0; i < n; i++) {

				printf("%d  ", (vector_a[i] - vector_b[i]));

			}printf("\n");
			break;
		case 2:
			/* Multiplication */
			printf("Multiplication of two vectors and b: \n");
			for (i = 0; i < n; i++) {

				printf("%d  ", (vector_a[i] * vector_b[i]));

			}printf("\n");
			break;
		case 3:
			/* Division */
			printf("Division of two vectors a and b: \n");
			for (i = 0; i < n; i++) {

				printf("%0.2f  ", (double)vector_a[i] / vector_b[i]);

			}printf("\n");
			break;
		}
		printf("\n");
	}
	end = clock();

	t_par = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Time taken for sequential execution:%f\n", t_seq);
	printf("Time taken for parallel execution:%f\n", t_par);

	double speed_up = 0;
	speed_up = t_seq /t_par;
	printf("SpeedUp:%f\n", speed_up);

	double efficiency = 0;
	int num_threads = 4;
	efficiency = speed_up/num_threads;
	printf("Efficiency:%f\n", efficiency);

	return 0;
}