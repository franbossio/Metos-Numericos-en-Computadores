#include <iostream>
#include <math.h> 
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	double a,b, suma, Iexacta, error;
	float h;
	double m[6][2] = {{0,0},{0.2,0.2},{0.4,0.4},{0.6,0.6},{0.8,0.8},{1,1}};
	int n=6-1;//filas - 1, cantidad de subintervalos
	printf("Ingresar los limites de integracion: ");
	scanf(" %lf", &a);
	scanf(" %lf", &b);
	printf("Ingresar la integral exacta: ");
	scanf(" %lf", &Iexacta);
	
	//Calcular I aproximado
	h=(float)m[1][0]-m[0][0];
	
	suma=m[0][1] + m[6-1][1];//m[0][1](primer valor) + m[filas - 1][1](ultimo valor);
	
	for(int i = 1 ;i <= n-1; i++){
		suma+=2*m[i][1];
	}
	suma=(h/2)*suma;
	
	error=abs(Iexacta-suma);
	
	printf("La integral es: %.2lf\n", suma);//suma=Iaprox
	printf("el error es: %.2lf", error);
	
	return 0;
}

	

