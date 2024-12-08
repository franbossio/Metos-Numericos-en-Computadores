#include <iostream>
#include <math.h> 
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	double a,b, suma, Iexacta, error;
	float h;
	double m[9][2] = {{0,0},{0.25,0.4135},{0.5,1.0243335},{0.75,1.88649975},{1,3.117},{1.25,4.8339575},{1.5,7.6175115},{1.75,11.3557815},{2,14.083952}};
	int n=9-1;//filas - 1, cantidad de subintervalos
	printf("Ingresar los limites de integracion: ");
	scanf(" %lf", &a);
	scanf(" %lf", &b);
	/*printf("Ingresar la integral exacta: ");
	scanf(" %lf", &Iexacta);*/
	
	//Calcular I aproximado
	h=(float)m[1][0]-m[0][0];
	
	suma=m[0][1] + m[n][1];//m[0][1](primer valor) + m[filas - 1][1](ultimo valor);
	
	for(int i = 1 ;i <= n-1; i++){
		suma+=2*m[i][1];
	}
	suma=(h/2)*suma;
	
	//error=abs(Iexacta-suma);
	
	printf("La integral es: %lf\n", suma);//suma=Iaprox
	//printf("el error es: %.2lf", error);
	
	return 0;
}

