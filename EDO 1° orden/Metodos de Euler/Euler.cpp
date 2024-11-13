#include <iostream>
#include <math.h> 
#include <stdlib.h>
using namespace std;
//definir la funcion
double f(double x, double y);

int main(int argc, char *argv[]) {
	double x_0, x_f, y_0, h;
	int n;
	printf("Ingresar x inicial y x fina(x_0,x_f): ");
	scanf(" %lf", &x_0);
	scanf(" %lf", &x_f);
	printf("Ingresar y inicial(y_0): ");
	scanf(" %lf", &y_0);
	printf("Ingresar h: ");
	scanf(" %lf", &h);
	//calcular la cantidad de intervalos
	n=(int)(x_f-x_0)/h;
	double x[100]={0},y[100]={0};
	
	//calcuar la solucion, tabla de datos
	x[0]=x_0;
	y[0]=y_0;
	
	for(int i = 0; i<n+1; i++){
		x[i+1]=x[i]+h;
		y[i+1] = y[i]+h*(2*f(x[i],y[i])-f(x[i-1],y[i-1]));
		printf("\nX%d = %lf\nY%d = %lf",i+1, x[i+1],i+1, y[i+1]);
	}
	
	return 0;
}

//dy/dx = f(x,y)
double f(double x, double y){
	return (x*exp(pow(x,2)))/y;
}
