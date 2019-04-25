#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main(){
	
	int n, p;
	scanf("%i %i", &n, &p);
	
	while(n!=0 && p!=0){
		int k, i;
		if(n%p==0)
			k=n/p;
		else
			k=n/p + 1;


		printf("Poo");

		for(i=6; i<k; i++){
			printf("o");
			if(i==19)
				break;
		}

		printf("dle\n");


		scanf("%i %i", &n, &p);
	}
}