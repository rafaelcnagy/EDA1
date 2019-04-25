int check(int tela[320][240], int logo[10][10], int ti, int tj, int num, int X, int Y,int id[320][240]){

	bool ward=true;
	int i=0, j=0;
	
	while (ward==true){

		if(logo[i][j]!=tela[ti+i][tj+j] || id[ti+i][tj+j]==1){
			ward=false;
		}
		else if(i==(Y-1) && j==(X-1)){

			num++;
			marcacao(id,tela,ti,tj,X,Y);
			break;
		}
		else if(j==X-1){
			j=0;
			i++;
		}
		else
			j++;
	}
	return num;
}