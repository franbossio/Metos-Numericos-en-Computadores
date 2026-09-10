#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

// ==================== CAMBIAR EN CADA EJERCICIO ====================
// Unica parte que hay que tocar a mano: la funcion a integrar.
double f(double x){
	return x;
}
// =====================================================================

int main(int argc, char *argv[]) {
	double a,b, suma,x, Iexacta, error;
	double h;
	int n;
	printf("Ingresar los limites de integracion: ");
	scanf(" %lf", &a);
	scanf(" %lf", &b);
	printf("Ingresar la cantidad de subintervalos: ");
	scanf(" %d", &n);
	printf("Ingresar la integral exacta: ");
	scanf(" %lf", &Iexacta);

	//Calcular I aproximado
	h=(b-a)/n;

	suma=f(a)+f(b);

	for(int i = 1 ;i <= n-1; i++){
		x=a+i*h;
		suma+=2*f(x);
	}
	suma=(h/2)*suma;

	//calcular error
	error=fabs(Iexacta-suma);

	printf("La integral es: %.2lf\n", suma);//suma=Iaprox
	printf("el error es: %.2lf", error);

	return 0;
}
