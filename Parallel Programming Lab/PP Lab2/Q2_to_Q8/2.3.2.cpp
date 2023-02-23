#include <stdio.h>
#include<time.h>
int main(){
	
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int even_sum = 0;
	int odd_sum = 0;
	clock_t start, end;
    double t_seq;
	start = clock();
	for (int i = 0; i < 10; i++) {
		 if (arr[i] % 2 == 0) {
			even_sum += arr[i];
		 }
	  }
	  
	  for (int i = 0; i < 10; i++) {
		 if (arr[i] % 2 != 0) {
			odd_sum += arr[i];
		 }
	  }
	  printf("Sum of even numbers: %d\n", even_sum);
	  printf("Sum of odd numbers: %d\n", odd_sum);
	  end = clock();
	  
	  t_seq = double(end-start)/CLOCKS_PER_SEC;
	  printf("Execution time: %f\n", t_seq);
	  
	  return 0;
}
