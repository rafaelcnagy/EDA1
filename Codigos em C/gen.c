#include<stdlib.h>
#include<string.h>
#include<stdio.h>


int main(){
	
	int n, p, i, j;
	scanf("%i %i", &n, &p);
	char vet[100][25];
	char aux, aux20[25];

	getchar();
	for(i=0; i<n; i++){
		fgets(vet[i], 25, stdin);
	}

	
	for (i = 0; i < n-1; i++){  
       	for (j = 0; j < n-i-1; j++){
           	if (strcmp(vet[j],vet[j+1]) > 0){
            	strcpy(aux20, vet[j]);
            	strcpy(vet[j], vet[j+1]);
            	strcpy(vet[j+1], aux20);
            }
        }
    }


    i=0;
    while(vet[p-1][i] == ' ' || vet[p-1][i] == '\n'){
    	i++;
    }
    while(vet[p-1][i] != '\n' && vet[p-1][i] != '\0'){
    	printf("%c",vet[p-1][i]);
    	i++;
    }
    printf("\n");	
    

}