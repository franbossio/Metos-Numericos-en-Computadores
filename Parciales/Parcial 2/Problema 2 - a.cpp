#include <iostream>
#include <math.h> 
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	double suma, Iexacta, error, errorp;
	float h;
	double m[11][2] = {{1,-1.323925},{1.1, -1.496075},{1.2,-1.644029},{1.3,-1.689147},{1.4,-1.635683},{1.5,-1.492435},{1.6,-1.272529},{1.7,-0.983024},{1.8,-0.568956},{1.9,-0.14099},{2,0.241050}};
	int n=11-1;//filas - 1, cantidad de subintervalos
	
	Iexacta=2.0596753;
	
	//Calcular I aproximado
	h=(float)m[1][0]-m[0][0];
	
	suma=m[0][1] + m[6-1][1];//m[0][1](primer valor) + m[filas - 1][1](ultimo valor);
	
	for(int i = 1 ;i <= n-1; i++){
		suma+=2*m[i][1];
	}
	suma=(h/2)*suma;
	
	error=abs(Iexacta-suma);
	errorp=(abs(Iexacta-suma)/abs(Iexacta))*100;

	printf("La integral es: %lf\n", suma);//suma=Iaprox
	printf("El error absoluto es: %lf", error);
	printf("\nEl error porcentual es: %lf", errorp);
	
	return 0;
}
