#include <iostream>
#include <math.h> 
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	//tabla de datos ya escrita(cambia en cada problema)
	double m[9][2]={{0,1},{0.25,1.384},{0.5,1.849},{0.75,2.417},{1,3.118},{1.25,3.99},{1.5,5.082},{1.75,6.45},{2,8.189}};
	double h, derivada;
	int operador, grado, i=8,x;//filas - 1(el i se cambia en cada problema);
	h=m[1][0]-m[0][0];
	printf("Elige el operador en direncias finitas:");
	printf("\n1.Hacia adelante(no valido para el ultimo elemento)");
	printf("\n2.Hacia atras(no valido para el primer elemento)");
	printf("\n3.Centrado(no valido para el primer y ultimo elemento)");
	scanf(" %d", &operador);
	printf("\nElige el grado de derivada(hasta 4): ");
	scanf(" %d", &grado);
	
	//ingreso el valor de la posicion del numero a derivar, esto es independiente a cada problema
	x=3; //m[3][0]

	switch(operador){
	case 1:
		switch(grado){
		case 1:
			derivada=(m[x+1][1]-m[x][1])/h;
			if(x+2<=i){
				derivada=(-m[x+2][1]+4*m[x+1][1]-3*m[x][1])/(2*h);
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
			}
			break;
		case 2: 
			if(x-2<=0){
				derivada=(m[x][1]-2*m[x-1][1]+m[x-2][1])/pow(h,2);
			}else if(x-3<=0){
				derivada=(2*m[x][1]-5*m[x-1][1]+4*m[x-2][1]-m[x-3][1])/pow(h,2);
			}else{
				printf("No es posible hacer la derivada");
				return 1;
			}
			break;
		case 3: 
			if(x-3<=0){
				derivada=(m[x][1]-3*m[x-1][1]+3*m[x-2][1]-m[x-3][1])/pow(h,3);
			}else if(x-4<=0){
				derivada=(5*m[x][1]-18*m[x-1][1]+24*m[x-2][1]-14*m[x-3][1]+3*m[x-4][1])/(2*pow(h,3));
			}else{
				printf("No es posible hacer la derivada");
				return 1;
			}
			break;
		case 4: 
			if(x-4<=0){
				derivada=(m[x][1]-4*m[x-1][1]+6*m[x-2][1]-4*m[x-3][1]+m[x-4][1])/pow(h,4);
			}else if(x-5<=0){
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
				derivada=(-m[x+3][1]+12*m[x+2][1]+39*m[x+1][1]+56*m[x][1]-39*m[x-1][1]+12*m[x-2][1]+m[x-3][1])/(6*pow(h,4));
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
	printf("La derivada de grado %d en el punto x=%.2lf es: %.2lf", grado, m[x][0], derivada);
	return 0;
}

