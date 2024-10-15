#include <iostream>
#include <math.h> 
#include <stdlib.h>
#define PI 3.14159265358979323846
using namespace std;
//declarar funcion
double f(double x);
double f2(double x);
void trapecio(double a, double b, int n);
void simpson(double a, double b, int n);

int main(int argc, char *argv[]) {
	double a,b,a2,b2;
	int n, n2;
	a=0;
	b=1;
	n=10;
	a2=0;
	b2=PI/4;
	n2=20;
	//cambiar la funcion y los intervalos a mano
	printf("Trapecio:\n");
	trapecio(a2,b2,n);
	printf("simpson:\n");
	simpson(a2,b2,n2);
	return 0;
}
double f(double x){
	return sqrt(1+9*pow(x,4));
}
double f2(double x){
	return sqrt(1+pow(cos(x),2));
}
void trapecio(double a, double b, int n){
	double x,suma;
	float h;
	//Calcular I aproximado
	h=(float)(b-a)/n;
	
	suma=f2(a)+f2(b);
	
	for(int i = 1 ;i <= n-1; i++){
		x=a+i*h;
		suma+=2*f2(x);
	}
	suma=(h/2)*suma;
		
	printf("La integral es: %lf\n", suma);//suma=Iaprox
}
void simpson(double a, double b, int n){
	double x, suma;
	float h;
	//Calcular I aproximado
	h=(float)(b-a)/n;
	
	suma=0;
	
	for(int i = 1 ;i <= (n/2)-1; i++){
		x=a+2*i*h;
		suma=suma+2*f2(x)+4*f2(x-h);
	}
	suma=(h/3)*(4*f2(x-h)+f2(a)+f2(b)+suma);
	
	printf("La integral es: %lf\n", suma);//suma=Iaprox
}
	
