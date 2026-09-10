#include <iostream>
#include <math.h>
#include <stdlib.h>
#define FILAS 100
using namespace std;

int main(int argc, char *argv[]) {
	double m[FILAS][2];
	double h, derivada;
	int operador, grado, filas, i, x;

	printf("Ingresar la cantidad de puntos de la tabla: ");
	scanf("%d", &filas);
	if (filas < 2 || filas > FILAS) {
		printf("\nCantidad de puntos invalida (debe ser entre 2 y %d).\n", FILAS);
		return 1;
	}
	printf("Ingresar los %d puntos (formato por punto: x y), con paso constante:\n", filas);
	for (int k = 0; k < filas; k++) {
		scanf("%lf %lf", &m[k][0], &m[k][1]);
	}
	i = filas - 1; //ultimo indice valido de la tabla
	h = m[1][0]-m[0][0];

	printf("Elige el indice del punto de la tabla donde derivar (0 a %d): ", i);
	scanf(" %d", &x);
	if (x < 0 || x > i) {
		printf("\nIndice fuera de la tabla.\n");
		return 1;
	}

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
			derivada=(m[x+1][1]-m[x][1])/h;
			if(x+2<=i){
				derivada=(-m[x+2][1]+4*m[x+1][1]-3*m[x][1])/(2*h);
				printf("Usaste 2 orden");
			}
			break;
		case 2:
			if(x+2<=i){
				derivada=(m[x+2][1]-2*m[x+1][1]+m[x][1])/pow(h,2);
			}else if(x+3<=i){
				derivada=(-m[x+3][1]+4*m[x+2][1]-5*m[x+1][1]+2*m[x][1])/pow(h,2);
			}else{
				printf("No es posible hacer la derivada");
				return 1;
			}
			break;
		case 3:
			if(x+3<=i){
				derivada=(m[x+3][1]-3*m[x+2][1]+3*m[x+1][1]-m[x][1])/pow(h,3);
			}else if(x+4<=i){
				derivada=(-3*m[x+4][1]+14*m[x+3][1]-24*m[x+2][1]+18*m[x+1][1]-5*m[x][1])/(2*pow(h,3));
			}else{
				printf("No es posible hacer la derivada");
				return 1;
			}
			break;
		case 4:
			if(x+4<=i){
				derivada=(m[x+4][1]-4*m[x+3][1]+6*m[x+2][1]-4*m[x+1][1]+m[x][1])/pow(h,4);
			}else if(x+5<=i){
				derivada=(-2*m[x+5][1]+11*m[x+4][1]-24*m[x+3][1]+26*m[x+2][1]-14*m[x+1][1]+3*m[x][1])/pow(h,4);
			}else{
				printf("No es posible hacer la derivada");
				return 1;
			}
			break;
		}
		break;
	case 2:
		switch(grado){
		case 1:
			derivada=(m[x][1]-m[x-1][1])/h;
			if(x-2>=0){
				derivada=(3*m[x][1]-4*m[x-1][1]+m[x-2][1])/(2*h);
				printf("Usaste 2 orden");
			}
			break;
		case 2:
			if(x-2>=0){
				derivada=(m[x][1]-2*m[x-1][1]+m[x-2][1])/pow(h,2);
			}else if(x-3>=0){
				derivada=(2*m[x][1]-5*m[x-1][1]+4*m[x-2][1]-m[x-3][1])/pow(h,2);
			}else{
				printf("No es posible hacer la derivada");
				return 1;
			}
			break;
		case 3:
			if(x-3>=0){
				derivada=(m[x][1]-3*m[x-1][1]+3*m[x-2][1]-m[x-3][1])/pow(h,3);
			}else if(x-4>=0){
				derivada=(5*m[x][1]-18*m[x-1][1]+24*m[x-2][1]-14*m[x-3][1]+3*m[x-4][1])/(2*pow(h,3));
			}else{
				printf("No es posible hacer la derivada");
				return 1;
			}
			break;
		case 4:
			if(x-4>=0){
				derivada=(m[x][1]-4*m[x-1][1]+6*m[x-2][1]-4*m[x-3][1]+m[x-4][1])/pow(h,4);
			}else if(x-5>=0){
				derivada=(3*m[x][1]-14*m[x-1][1]+26*m[x-2][1]-24*m[x-3][1]+11*m[x-4][1]-2*m[x-5][1])/pow(h,4);
			}else{
				printf("No es posible hacer la derivada");
				return 1;
			}
			break;
		}
		break;
	case 3:
		switch(grado){
		case 1:
			derivada=(m[x+1][1]-m[x-1][1])/(2*h);
			if(x-2>=0 && x+2<=i){
				derivada=(-m[x+2][1]+8*m[x+1][1]-8*m[x-1][1]+m[x-2][1])/(12*h);
				printf("Usaste 2 orden");
			}
			break;
		case 2:
			if(x-1>=0 && x+1<=i){
				derivada=(m[x+1][1]-2*m[x][1]+m[x-1][1])/pow(h,2);
			}else if(x-2>=0 && x+2<=i){
				derivada=(-m[x+2][1]+16*m[x+1][1]-30*m[x][1]+16*m[x-1][1]-m[x-2][1])/(12*pow(h,2));
			}else{
				printf("No es posible hacer la derivada");
				return 1;
			}
			break;
		case 3:
			if(x-2>=0 && x+2<=i){
				derivada=(m[x+2][1]-2*m[x+1][1]+2*m[x-1][1]-m[x-2][1])/(2*pow(h,3));
			}else if(x-3>=0 && x+3<=i){
				derivada=(-m[x+3][1]+8*m[x+2][1]-13*m[x+1][1]+13*m[x-1][1]-8*m[x-2][1]+m[x-3][1])/(8*pow(h,3));
			}else{
				printf("No es posible hacer la derivada");
				return 1;
			}
			break;
		case 4:
			if(x-2>=0 && x+2<=i){
				derivada=(m[x+2][1]-4*m[x+1][1]+6*m[x][1]-4*m[x-1][1]+m[x-2][1])/pow(h,4);
			}else if(x-3>=0 && x+3<=i){
				derivada=(-m[x+3][1]+12*m[x+2][1]-39*m[x+1][1]+56*m[x][1]-39*m[x-1][1]+12*m[x-2][1]-m[x-3][1])/(6*pow(h,4));
			}else{
				printf("No es posible hacer la derivada");
				return 1;
			}
			break;
		}
		break;
	default:
		printf("La opcion ingresada no esta disponible");
		return 1;
	}
	printf("La derivada de grado %d en el punto x=%.2lf es: %lf", grado, m[x][0], derivada);
	return 0;
}
