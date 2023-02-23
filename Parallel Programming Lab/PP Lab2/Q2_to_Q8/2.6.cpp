#include <stdio.h>
#include <math.h>
#include <omp.h> 
int is_prime(int num) {
if (num <= 1) return 0;
for (int i = 2; i <= sqrt(num); i++) {
	if (num % i == 0) return 0;
}
return 1;
}
int main() {
int start, end;
	printf("Enter the start number: ");
	scanf("%d", &start);
	printf("Enter the end number: ");
	scanf("%d", & end);
#pragma omp parallel for shared(start, end)

		for (int i = start; i <= end; i++) {
			if (is_prime(i)) {
				printf("%d is a prime number (thread %d)\n", i, omp_get_thread_num());
			}
		}
	return 0;
}
