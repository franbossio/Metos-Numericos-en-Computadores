#include <iostream>
#include <math.h>
#include <stdlib.h>
#define FILAS 100
using namespace std;

int main(int argc, char *argv[]) {
	double a,b, suma, Iexacta, error;
	double h;
	double m[FILAS][2];
	int filas, n;

	printf("Ingresar la cantidad de puntos de la tabla: ");
	scanf("%d", &filas);
	if (filas < 2 || filas > FILAS) {
		printf("\nCantidad de puntos invalida (debe ser entre 2 y %d).\n", FILAS);
		return 1;
	}
	printf("Ingresar los %d puntos (formato por punto: x y), con paso constante:\n", filas);
	for (int i = 0; i < filas; i++) {
		scanf("%lf %lf", &m[i][0], &m[i][1]);
	}
	n = filas - 1; //cantidad de subintervalos

	printf("Ingresar la integral exacta: ");
	scanf(" %lf", &Iexacta);

	a = m[0][0];
	b = m[n][0];

	//Calcular I aproximado
	h = m[1][0]-m[0][0];

	suma=m[0][1] + m[n][1];//m[0][1](primer valor) + m[filas - 1][1](ultimo valor);

	for(int i = 1 ;i <= n-1; i++){
		suma+=2*m[i][1];
	}
	suma=(h/2)*suma;

	error=fabs(Iexacta-suma);

	printf("\nLa integral entre a=%lf y b=%lf es: %.2lf\n", a, b, suma);//suma=Iaprox
	printf("el error es: %.2lf", error);

	return 0;
}
