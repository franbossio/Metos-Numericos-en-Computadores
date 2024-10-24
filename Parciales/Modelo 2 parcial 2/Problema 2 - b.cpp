#include <iostream>
#include <math.h> 
#include <stdlib.h>
using namespace std;
//declarar funcion
double f(double x);

int main(int argc, char *argv[]) {
	double a,b, suma, suma2,x, Iexacta, error, I;
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
	
	suma=0;
	suma2=0;
	
	for(int i = 0 ;i <= n-1; i++){
		x=a+i*h;
		suma+=f(x);
	}
	
	for(int i = 0 ;i <= n-1; i++){
		x=a+i*h;
		suma2+=(f(x+h)-f(x));
	}
	I=h*suma+(h/2)*suma2;
	
	//calcular error
	error=abs(Iexacta-I);
	
	printf("La integral es: %lf\n", I);//suma=Iaprox
	printf("el error es: %lf", error);
	
	return 0;
}
double f(double x){
	return 3*pow(x,2)+1;
}
