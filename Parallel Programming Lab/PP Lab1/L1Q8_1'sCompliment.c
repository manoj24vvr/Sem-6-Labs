#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


int ones_complement_bin(int num) {
	int ans=0,i=0,dig;
	while(num>0) {
		dig = num% 2;
		ans += (!dig)*pow(10,i);
		num /= 2;
		i++;
	}
	return ans;
}

int ones_complement_num(int num) {
	int ans=0,i=0,dig;
	while(num>0) {
		dig = num% 2;
		ans += pow(2,i)* !dig;
		num /= 2;
		i++;
	}
	return ans;
}
int main() {
	int n,m,i,j,k,len;
	printf("Enter dimensions of matrix: ");
	scanf("%d%d",&n,&m);
	int mat[n][m],res[n][m],final[n][m];
	printf("Enter the matrix: \n");
	for(i=0; i<n; i++) {
		printf("Row %d: ",i+1);
		for(j=0; j<m; j++) {
			scanf("%d",&mat[i][j]);
		}
	}

	clock_t t = clock();

	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			if(i==0 ||j==0||i==n-1 || j==m-1) {
				res[i][j] = mat[i][j];
				final[i][j] = mat[i][j];
			} else {
				res[i][j]= ones_complement_bin(mat[i][j]);
				final[i][j]= ones_complement_num(mat[i][j]);
			}
		}
	}
	t = clock() - t;

	printf("The Resultant Matrix B: \n");
	for(i=0; i<n; i++) {
//		printf("Row %d: ",i+1);
		for(j=0; j<m; j++) {
			printf("%d\t",res[i][j]);
		}
		printf("\n");
	}

	printf("The Final Matrix D: \n");
	for(i=0; i<n; i++) {
//		printf("Row %d: ",i+1);
		for(j=0; j<m; j++) {
			printf("%d\t",final[i][j]);
		}
		printf("\n");
	}


	double time_taken = ((double)t/CLOCKS_PER_SEC); // in seconds

	printf("\nThe Current Program took %f Milli seconds to execute!\n", (time_taken)*1000);

	return 0;
}
