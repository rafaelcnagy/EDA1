#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void algo(int cap, int max, int *p){

	if(cap <= max){
		(*p)++;
	}
	else{
		if(cap%2 == 0){
			algo(cap/2, max, p);
			algo(cap/2, max, p);
		}
		else{
			algo(1+cap/2, max, p);
			algo(cap/2, max, p);
		}
	}

}

int main(void) {
	int n,k,i,j;
 
	scanf(" %i %i", &n, &k);
	while (n!=0 && k!=0){
 
		int *p = malloc(sizeof(int));
		algo(n, k, p);

		printf("%i\n", *p);
 
		scanf(" %i %i", &n, &k);
	}
	return 0;
}