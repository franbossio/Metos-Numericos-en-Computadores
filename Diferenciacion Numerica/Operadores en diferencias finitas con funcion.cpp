#include <iostream>
#include <math.h> 
#include <stdlib.h>
using namespace std;
//declarar funcion
double f(double x);

int main(int argc, char *argv[]) {
	double h, derivada,x;
	int operador, grado;
	//ingreso el valor de x para derivar f'(x)
	printf("Ingrese el valor de x para derivar en ese punto: ");
	scanf(" %lf", &x);
	printf("Ingrese h: ");
	scanf(" %lf", &h);
	printf("Elige el operador en direncias finitas:");
	printf("\n1.Hacia adelante(no valido para el ultimo elemento)");
	printf("\n2.Hacia atras(no valido para el primer elemento)");
	printf("\n3.Centrado(no valido para el primer y ultimo elemento)");
	scanf(" %d", &operador);
	printf("\nElige el grado de derivada(hasta 4): ");
	scanf(" %d", &grado);
	
	switch(operador){
	case 1:
		switch(grado){
		case 1:
			derivada=(-f(x+2*h)+4*f(x+h)-3*f(x))/(2*h);
			break;
		case 2: 
			derivada=(-f(x+3*h)+4*f(x+2*h)-5*f(x+h)+2*f(x))/pow(h,2);
			break;
		case 3: 
			derivada=(-3*f(x+4*h)+14*f(x+3*h)-24*f(x+2*h)+18*f(x+h)-5*f(x))/(2*pow(h,3));
			break;
		case 4: 
			derivada=(-2*f(x+5*h)+11*f(x+4*h)-24*f(x+3*h)+26*f(x+2*h)-14*f(x+h)+3*f(x))/pow(h,4);
			break;
		}
		break;
	case 2:
		switch(grado){
		case 1:
			derivada=(3*f(x)-4*f(x-h)+f(x-2*h))/(2*h);
			break;
		case 2: 
			derivada=(2*f(x)-5*f(x-h)+4*f(x-2*h)-f(x-3*h))/pow(h,2);
			break;
		case 3: 
			derivada=(5*f(x)-18*f(x-h)+24*f(x-2*h)-14*f(x-3*h)+3*f(x-4*h))/(2*pow(h,3));
			break;
		case 4: 
			derivada=(3*f(x)-14*f(x-h)+26*f(x-2*h)-24*f(x-3*h)+11*f(x-4*h)-2*f(x-5*h))/pow(h,4);
			break;
		}
		break;
	case 3: 
		switch(grado){
		case 1:
			derivada=(-f(x+2*h)+8*f(x+h)-8*f(x-h)+f(x-2*h))/(12*h);
			break;
		case 2: 
			derivada=(-f(x+2*h)+16*f(x+h)-30*f(x)+16*f(x-h)-f(x-2*h))/(12*pow(h,2));
			break;
		case 3: 
			derivada=(-f(x+3*h)+8*f(x+2*h)-13*f(x+h)+13*f(x-h)-8*f(x-2*h)+f(x-3*h))/(8*pow(h,3));
			break;
		case 4: 
			derivada=(-f(x+3*h)+12*f(x+2*h)+39*f(x+h)+56*f(x)-39*f(x-h)+12*f(x-2*h)+f(x-3*h))/(6*pow(h,4));
			break;
		}
		break;
	default: 
		printf("La opcion ingresada no esta disponible");
		return 1;
	}
	printf("La derivada de grado %d en el punto x=%.2lf es: %.2lf", grado, x, derivada);
	return 0;
}

double f(double x){
	return pow(x,4);
}
