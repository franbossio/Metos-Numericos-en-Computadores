#include <iostream>
#include <math.h> 
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	double a,b, suma, Iexacta, error;
	float h;
	double m[11][2] = {{1,5.381},{1.1,6.526702},{1.2,7.635878},{1.3,8.672},{1.4,9.592},{1.5,10.332953},{1.6,10.853},{1.7,11.123221},{1.8,11.134},{1.9,10.898786},{2,10.435}};
	int n=11-1;//filas - 1, cantidad de subintervalos
	a=m[0][0];
	b=m[n][0];
	//printf("Ingresar la integral exacta: ");
	//scanf(" %lf", &Iexacta);
	
	//Calcular I aproximado
	h=(float)m[1][0]-m[0][0];
	
	suma=0;
	
	for(int i = 1 ;i <= (n/2)-1; i++){
		suma=suma+2*m[2*i][1]+4*m[2*i-1][1];
	}
	suma=(h/3)*(4*m[n-1][1]+m[0][1]+m[n][1]+suma);
	
	//error=abs(Iexacta-suma);
	
	printf("La integral es: %lf\n", suma);//suma=Iaprox
	//printf("el error es: %.2lf", error);
	
	return 0;
}
