#include<stdio.h>
#include<stdlib.h>
#include<time.h>

clock_t st,end,in,out;

void pattern(char ch, int val){
	int j;
	for(j=0;j<val;j++)
		printf("%c",ch);
}

int main(){
	st = clock();
	double dur =0;
	int n,m,i,j,k,len;
	printf("Enter dimensions of matrix: ");
	in = clock();
	scanf("%d%d",&n,&m);
	char ch[n][m];
	int mat[n][m];
	fflush(stdin);
	printf("Enter the character matrix: \n");
	for(i=0;i<n;i++){
		printf("Row %d: ",i+1);
		for(j=0;j<m;j++){
			scanf(" %c",&ch[i][j]);
		}
	}
	
	printf("Enter the value matrix: \n");
	for(i=0;i<n;i++){
		printf("Row %d: ",i+1);
		for(j=0;j<m;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	out = clock();
	dur = dur -(double)out + in;
	printf("Pattern: ");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			pattern(ch[i][j],mat[i][j]);
		}
	}
	end = clock();
	dur = (dur+ (double)end-st)/CLOCKS_PER_SEC;
	printf("\nEstimated Execution Time: %.2f ms\n",dur*1000);
	return 0;
}
