#include <iostream>
#include <math.h> 
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	double a,b, suma, Iexacta, error;
	float h;
	double m[9][2] = {{0,0},{0.125,0.125},{0.25,0.25},{0.375,0.375},{0.5,0.5},{0.625,0.625},{0.75,0.75},{0.875,0.875},{1,1}};
	int n=9-1;//filas - 1, cantidad de subintervalos
	printf("Ingresar los limites de integracion: ");
	scanf(" %lf", &a);
	scanf(" %lf", &b);
	printf("Ingresar la integral exacta: ");
	scanf(" %lf", &Iexacta);
	
	//Calcular I aproximado
	h=(float)m[1][0]-m[0][0];
	
	suma=0;
	
	for(int i = 1 ;i <= (n/2)-1; i++){
		suma=suma+2*m[2*i][1]+4*m[i][1];
	}
	suma=(h/2)*suma;
	
	error=abs(Iexacta-suma);
	
	printf("La integral es: %.2lf\n", suma);//suma=Iaprox
	printf("el error es: %.2lf", error);
	
	return 0;
}

