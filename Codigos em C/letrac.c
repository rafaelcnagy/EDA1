#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main(){
	
	int n, t1=0, t2=0, i;
	scanf("%i", &n);
	int v[n];
	for(i=0; i<n; i++){
		int aux;
		scanf("%i", &aux);
		v[i]=aux;
		t2+=aux;
	}
	for(i=0; i<n; i++){
		t1+=v[i];
		t2-=v[i];
		if(t1==t2)
			break;
	}
	printf("%i\n", i+1);
}