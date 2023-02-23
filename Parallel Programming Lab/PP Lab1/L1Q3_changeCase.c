#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>


int main(){
	
	clock_t time;
    
	char str[100];
  	int i;
  	
  	printf("\n Please Enter any String: ");
  	gets(str);
  	
	time = clock();

  	for (i = 0; str[i]!='\0'; i++)
  	{
  	    if(str[i] >= 'A' && str[i] <= 'Z') 
            str[i] = str[i] + 32; 
              
              
        else if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
  		
  	}

	
	printf("The string after changing case of letters is: %s \n", str);
	
    time = clock() - time;
    double time_spent = (double)(time) / CLOCKS_PER_SEC;	
	printf("\n\nTime taken to execute: %f \n", time_spent);
	
	return 0;
	 
}
