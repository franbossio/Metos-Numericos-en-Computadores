#include <stdio.h>
#include <math.h>

double f(double);
double fPrima(double);
void NewtonRaphson();


int main (){
	NewtonRaphson();
	return 0;
}
	
double f(double x){
	return 2*x+log10(x)-sin(3*x);////
}
double fPrima(double x, double h){
	return (3*f(x)-4*f(x-h)+f(x-2*h))/(2*h);////
}
void NewtonRaphson(){
	double xViejo , error , tolerancia , xNuevo;
	int contador = 0;
	tolerancia = 1e-6;
	double h = 0.01;
	printf("Ingrese el punto inicial\n"); 
	scanf("%lf", &xViejo);
	do{
		contador ++ ;
		xNuevo = xViejo - (f(xViejo)/fPrima(xViejo,h));
		if(abs(fPrima(xNuevo,h)) < 1e-10){
			printf("\n********\nDERIVADA GRANDE********\n");
			break;
		} 
		
		error = abs(xNuevo - xViejo);
		xViejo = xNuevo;
		
		
	}while(error > tolerancia && contador < 10000 );
	
	printf("\n\n\nLa raiz de f es: %.10lf", xNuevo);
	printf("\nEl valor del error en la raiz es de: %.10lf", error);
	printf("\nLa resolucion del problema %d iteraciones", contador);
}
