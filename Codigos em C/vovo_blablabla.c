#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	int n, i, aux1, aux2, dif, teste=0;
 
	scanf(" %i", &n);
	while (n!=0){
 		teste++;
 		int j[n], z[n];

 		for(i=0; i<n; i++){
 			scanf(" %i %i", &j[i], &z[i]);
 			
 		}
		
		printf("Teste %i\n", teste);
		dif=0;
		for(i=0; i<n; i++){
			dif+=(j[i]-z[i]);
			printf("%i\n", dif);
		}
 		printf("\n");

		scanf(" %i", &n);
	}
	return 0;
}