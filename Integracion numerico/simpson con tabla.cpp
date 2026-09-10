#include <iostream>
#include <math.h>
#include <stdlib.h>
#define FILAS 100
using namespace std;

int main(int argc, char *argv[]) {
	double a,b, suma;
	double h;
	double m[FILAS][2];
	int filas, n;

	printf("Ingresar la cantidad de puntos de la tabla (debe ser impar, subintervalos par): ");
	scanf("%d", &filas);
	while (filas < 3 || filas > FILAS || (filas - 1) % 2 != 0) {
		printf("Cantidad invalida (impar, entre 3 y %d). Ingrese otra: ", FILAS);
		scanf("%d", &filas);
	}
	printf("Ingresar los %d puntos (formato por punto: x y), con paso constante:\n", filas);
	for (int i = 0; i < filas; i++) {
		scanf("%lf %lf", &m[i][0], &m[i][1]);
	}
	n = filas - 1; //cantidad de subintervalos

	a=m[0][0];
	b=m[n][0];

	//Calcular I aproximado
	h = m[1][0]-m[0][0];

	suma=0;

	for(int i = 1 ;i <= (n/2)-1; i++){
		suma=suma+2*m[2*i][1]+4*m[2*i-1][1];
	}
	suma=(h/3)*(4*m[n-1][1]+m[0][1]+m[n][1]+suma);

	printf("\nLa integral entre a=%lf y b=%lf es: %.2lf\n", a, b, suma);//suma=Iaprox

	return 0;
}
