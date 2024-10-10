#include <iostream>
#include <math.h> 
#include <stdlib.h>
using namespace std;
//declarar funcion
double f(double x);

int main(int argc, char *argv[]) {
	double a,b, suma,x, Iexacta, error;
	float h;
	int n;
	printf("Ingresar los limites de integracion: ");
	scanf(" %lf", &a);
	scanf(" %lf", &b);
	printf("Ingresar la cantidad de subintervalos: ");
	scanf(" %d", &n);
	printf("Ingresar la integral exacta: ");
	scanf(" %lf", &Iexacta);
	
	//Calcular I aproximado
	h=(float)(b-a)/n;
	
	suma=f(a)+f(b);
	
	for(int i = 1 ;i <= n-1; i++){
		x=a+i*h;
		suma+=2*f(x);
	}
	suma=(h/2)*suma;
	
	//calcular error
	error=abs(Iexacta-suma);
	
	printf("La integral es: %.2lf\n", suma);//suma=Iaprox
	printf("el error es: %.2lf", error);
	
	return 0;
}
double f(double x){
	return x;
}
