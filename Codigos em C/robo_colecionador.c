#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int n,m,s,i,j;
 
	scanf(" %i %i %i", &n, &m, &s);
	while (n!=0 && m!=0 && s!=0){
 
		char pista[n][m];
		int num=0;
 
		for(i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf(" %c",&pista[i][j]);
 
 
		char rot='A';
		int x,y;
 
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				if(pista[i][j]=='N'){
					x=j;
					y=i;
					rot='N';
					break;
				}
				else if(pista[i][j]=='S'){
					x=j;
					y=i;
					rot='S';
					break;
				}
				else if(pista[i][j]=='L'){
					x=j;
					y=i;
					rot='L';
					break;
				}
				else if(pista[i][j]=='O'){
					x=j;
					y=i;
					rot='O';
					break;
				}
			}
			if(rot!='A')
				break;
		}
 
		char move;
 
		for (i=0; i<s; i++){
			scanf(" %c", &move);
			if(move=='D')
				switch(rot){
					case 'N':
						rot='L';
						break;
					case 'S':
						rot='O';
						break;
					case 'L':
						rot='S';
						break;
					case 'O':
						rot='N';
						break;
				}
			else if(move=='E')
				switch(rot){
					case 'N':
						rot='O';
						break;
					case 'S':
						rot='L';
						break;
					case 'L':
						rot='N';
						break;
					case 'O':
						rot='S';
						break;
				}
			else
				switch(rot){
					case 'N':
						if(y!=0 && pista[y-1][x]!='#'){
							y--;
							if(pista[y][x]=='*'){
								num++;
								pista[y][x]='.';
							}
						}
						break;
					case 'S':
						if(y!=n-1 && pista[y+1][x]!='#'){
							y++;
							if(pista[y][x]=='*'){
								num++;
								pista[y][x]='.';
							}
						}
						break;
					case 'L':
						if(x!=m-1 && pista[y][x+1]!='#'){
							x++;
							if(pista[y][x]=='*'){
								num++;
								pista[y][x]='.';
							}
						}
						break;
					case 'O':
						if(x!=0 && pista[y][x-1]!='#'){
							x--;
							if(pista[y][x]=='*'){
								num++;
								pista[y][x]='.';
							}
						}
						break;
				}
 
		}
		printf("%i\n", num);
 
		scanf(" %i %i %i", &n, &m, &s);
	}
	return 0;
}