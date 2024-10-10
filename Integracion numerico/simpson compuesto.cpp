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
	printf("Ingresar la cantidad de subintervalos(debe ser par): ");
	scanf(" %d", &n);
	while(n%2!=0){
		printf("la cantidad de subintervalos es impar, ingrese otra cantindad: ");
		scanf(" %d", &n);
	}
	printf("Ingresar la integral exacta: ");
	scanf(" %lf", &Iexacta);
	
	//Calcular I aproximado
	h=(float)(b-a)/n;
	
	suma=0;
	
	for(int i = 1 ;i <= (n/2)-1; i++){
		x=a+2*i*h;
		suma=suma+2*f(x)+4*f(x-h);
	}
	suma=(h/3)*(4*f(x-h)+f(a)+f(b)+suma);
	
	//calcular el error
	error=abs(Iexacta-suma);
	
	printf("La integral es: %.2lf\n", suma);//suma=Iaprox
	printf("el error es: %.2lf", error);
	
	return 0;
}
double f(double x){
	return x;
}
