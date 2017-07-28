#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int ran_x(int n_x);
int ran_y(int n_y);
float R(int n_y, int n_x, int *matriz,int ran_xi,int ran_yi,float ran_xf,float ran_yf);
int indice(int i, int j, int n_x, int n_y);
void texto(int ran_xi, int ran_yi, float r_old);

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
	
	
	srand (time(NULL)); 
	srand48(1);
	
	int n_x = 500;
	int n_y = 744;
	
	int iteraciones =10000;
	
	int ran_xi = ran_x(n_x);
	int ran_yi = ran_y(n_y);
	float ran_xf = ran_xi;
	float ran_yf = ran_yi;
	float r_old;
	float r_new;

	float alfa;
	float beta;
	beta = drand48();
	char s[200] = "Las coordenadas del punto mas alejado son:";
	char r[20] = "Radio:";
	//float n = ((1-2*drand48())*10);
	//printf("%f\n", n);
	
	r_old=R(n_y,n_x,matriz,ran_xi,ran_yi,ran_xf,ran_yf);
	//printf("%f\n", r_old);

	for(i=0;i<iteraciones;i++){
		int ran_xin = (int)ran_xi + ((1-2*drand48())*100);
		int ran_yin = (int)ran_yi + ((1-2*drand48())*100);
		float ran_xfn = ran_xin;
		float ran_yfn = ran_yin;
		r_new=R(n_y,n_x,matriz,ran_xin,ran_yin,ran_xfn,ran_yfn);
		alfa = exp((r_new-r_old));
	
	if(alfa>1){
		ran_xi = ran_xin;
		ran_yi = ran_yin;
		r_old=r_new;
	}
	else{
		if(alfa > beta){
			ran_xi = ran_xin;
			ran_yi = ran_yin;
			r_old=r_new;
		}
	}
			
	}
	printf("%s %d %d \n", s, ran_xi, ran_yi);	
	printf("%s %f\n", r, r_old);
	texto(ran_xi, ran_yi, r_old);
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

int indice(int i, int j, int n_x, int n_y){
	if(i > n_x){
	i = i % n_x; 
	}
	if(j > n_y){
	j = j % n_y; 
	}
	if(i < 0){
		i = n_x + i;
	}
	if(j < 0){
		j = n_y + j;
	}
	return n_y * i + j;
}

float R(int n_y, int n_x, int *matriz,int ran_xi,int ran_yi,float ran_xf,float ran_yf){
	
	int i;
	int j;
	int r;
	float distancia;
	
	if (matriz[indice(ran_xi,ran_yi,n_x,n_y)] != 1){
		for(r=1;r<n_x/2;r++){
			for(i=-r;i<r;i++){
				for(j=-r;j<r;j++){
					distancia = pow((pow((ran_xf+i)-ran_xf,2)+ pow((ran_yf+j)-ran_yf,2)),0.5);
					if(matriz[indice(ran_xi+i,ran_yi+j,n_x,n_y)] == 1 &&  distancia <= r){
						return distancia;
					}
				}
			}
		}
	}
}

void texto(int ran_xi, int ran_yi, float r_old){
	FILE *file;
	file=fopen("salida.txt","w");
	fprintf(file, "%d %d %f \n", ran_xi, ran_yi, r_old );
}


