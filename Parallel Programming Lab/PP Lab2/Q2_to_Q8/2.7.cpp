#include <stdio.h>
#include<string.h>
#include <omp.h>
int main() {
    char s[10] = "vENkAt";
#pragma omp parallel for shared(s)

for(int i = 0; i<strlen(s); i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i] = s[i] + 32;
		}
		else{
			s[i] = s[i] - 32;
		}
	}

printf("The string after toggle is %s", s);
return 0;
}
