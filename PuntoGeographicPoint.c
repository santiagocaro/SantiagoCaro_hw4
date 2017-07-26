#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int ran_x(int n_x);
int ran_y(int n_y);
float R(int n_y, int n_x, int *matriz);
float compara(int n_y, int n_x, int *matriz);

int main(){
	FILE*file;
	file=fopen("map_data.txt","r");

	int len=500*744;
	char line_buffer[len];
	char *split_buffer;
	const char *delimiter;
	delimiter=" ";
	int i=0;
	int j=0;
	int *matriz=malloc(500*744*sizeof(int));

	while(fgets(line_buffer,len,file)){
		j=0;
		split_buffer=strtok(line_buffer,delimiter);
		while(split_buffer != NULL){
			if (j != 0)
			{
				matriz[744*i+j]=atof(split_buffer);
				//printf("%d\n",matriz[744*i+j]);
			}
			split_buffer=strtok(NULL,delimiter);
			 
			j+=1;
	}
	i+=1;
	}
	//matriz[0][1]=23;
	//printf("%d\n",matriz[0][1]);
	
	srand (time(NULL)); 
	
	int n_x = 500;
	int n_y = 744;
	
	//ran_x(n_x);
	//ran_y(n_y);
	
	compara(n_y,n_x,matriz);
	
		
	
	return 0;
}            

int ran_x(int n_x){
	
	int rand_num = rand() % (n_x+1);
	return rand_num;
	//printf("%d\n",rand_num);
}
int ran_y(int n_y){
	int rand_num = rand() % (n_y+1);
	return rand_num;
	//printf("%d\n",rand_num);
}

float R(int n_y, int n_x, int *matriz){
	char s[200] = "Las coordenadas del punto mas alejado son:";
	int ran_xi = ran_x(n_x);
	int ran_yi = ran_y(n_y);
	float ran_xf = ran_xi;
	float ran_yf = ran_yi;
	//printf("%f\n",ran_yf+1); 
	//printf("%d\n",ran_yi);
	
	int r;
	float rf;
	int i;
	int j;
	float distancia;
	
	if (matriz[n_y*ran_xi+ran_yi] != 1){
		for(r=1;r<n_x/2;r++){
			for(i=-r;i<r;i++){
				for(j=-r;i<r;i++){
					distancia = pow((pow((ran_xf+i)-ran_xf,2)+ pow((ran_yf+j)-ran_yf,2)),0.5);
					if(matriz[n_y*(ran_xi+i)+(ran_yi+j)] == 1 &&  distancia <= r){
						return distancia;
						break;	
					}
				}
			}
		}
	printf("%f\n", distancia);
	printf("%s %d %d \n", s, ran_xi, ran_yi);
	}
}

float compara(int n_y, int n_x, int *matriz){
	float r_max = R(n_y,n_x,matriz);
	int n;
	for(n=0;n<100;n++){
		if(R(n_y,n_x,matriz)>r_max){
			r_max=R(n_y,n_x,matriz);
			return r_max;
		}
	}
	
}



